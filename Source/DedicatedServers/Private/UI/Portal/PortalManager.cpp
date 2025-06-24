// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/PortalManager.h"
#include "HttpModule.h"
#include "Data/API/APIData.h"
#include "JsonObjectConverter.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/IHttpResponse.h"
#include "Player/DSLocalPlayerSubsystem.h"
#include "UI/Interfaces/HUDManagement.h"
#include "GameFramework/HUD.h"


void UPortalManager::SignIn(const FString& Username, const FString& Password)
{
	SignInStatusMessageDelegate.Broadcast(TEXT("Signing in..."), false);
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::SignIn_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::PortalAPI::SignIn);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(10.f);

	LastUserName = Username;
	TMap<FString, FString> Params = {
	{TEXT("username"),	Username},
	{TEXT("password"),	Password}
	};
	const FString Content = SerializeJsonContent(Params);
	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::SignIn_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		SignInStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			SignInStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}

		FDSInitiateAuthResponse InitiateAuthResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &InitiateAuthResponse);
		
		UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetDSLocalPlayerSubsystem();
		if (IsValid(LocalPlayerSubsystem))
		{
			LocalPlayerSubsystem->InitializeTokens(InitiateAuthResponse.AuthenticationResult, this);
			LocalPlayerSubsystem->Username = LastUserName;
			LocalPlayerSubsystem->Email = InitiateAuthResponse.email;
		}
		InitiateAuthResponse.Dump();
		APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
		if (IsValid(LocalPlayerController))
		{
			if (IHUDManagement* HUDManagementInterface = Cast<IHUDManagement>(LocalPlayerController->GetHUD()))
			{
				HUDManagementInterface->OnSignIn();
			}
		}
	}
}

void UPortalManager::SignUp(const FString& Username, const FString& Password, const FString& Email)
{
	SignUpStatusMessageDelegate.Broadcast(TEXT("Creating a new account..."), false);
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::SignUp_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::PortalAPI::SignUp);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(10.f);

	LastUserName = Username;
	TMap<FString, FString> Params = {
	{TEXT("username"),	Username},
	{TEXT("password"),	Password},
	{TEXT("email"),		Email}
	};
	const FString Content = SerializeJsonContent(Params);
	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::SignUp_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}

		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &LastSignUpResponse);

		OnSignUpSucceeded.Broadcast();
	}
}

void UPortalManager::Confirm(const FString& ConfirmationCode)
{
	ConfirmStatusMessageDelegate.Broadcast("Checking verification code", false);
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::Confirm_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::PortalAPI::ConfirmSignUp);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("PUT"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(10.f);

	TMap<FString, FString> Params = {
	{TEXT("username"),	LastUserName},
	{TEXT("confirmationcode"),	ConfirmationCode}
	};
	const FString Content = SerializeJsonContent(Params);
	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::Confirm_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		ConfirmStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			if (JsonObject->HasField(TEXT("name")))
			{
				FString Exception = JsonObject->GetStringField(TEXT("name"));
				if (Exception.Equals(TEXT("CodeMismatchException")))
				{
					ConfirmStatusMessageDelegate.Broadcast("Incorrect verification code.", true);
					return;
				}
			}
			ConfirmStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}
	}
	OnConfirmSucceeded.Broadcast();
}



void UPortalManager::QuitGame()
{
	APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());

	if (IsValid(LocalPlayerController))
	{
		UKismetSystemLibrary::QuitGame(this, LocalPlayerController, EQuitPreference::Quit, false);

	}
}


void UPortalManager::RefreshTokens(const FString& RefreshToken)
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::RefreshTokens_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::PortalAPI::SignIn);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(10.f);

	TMap<FString, FString> Params = {
	{TEXT("refreshToken"),	RefreshToken}
	};

	const FString Content = SerializeJsonContent(Params);
	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::RefreshTokens_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful) return;

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			return;
		}

		FDSInitiateAuthResponse InitiateAuthResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &InitiateAuthResponse);

		UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetDSLocalPlayerSubsystem();
		if (IsValid(LocalPlayerSubsystem))
		{
			LocalPlayerSubsystem->UpdateTokens(InitiateAuthResponse.AuthenticationResult.AccessToken, InitiateAuthResponse.AuthenticationResult.IdToken);
		}
	}
}

void UPortalManager::SignOut(const FString& AccessToken)
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::SignOut_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::PortalAPI::SignOut);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetTimeout(10.f);

	TMap<FString, FString> Params = {
	{TEXT("accessToken"),	AccessToken}
	};
	const FString Content = SerializeJsonContent(Params);
	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::SignOut_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		return;
	}
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			return;
		}
	}
	if (UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetDSLocalPlayerSubsystem(); IsValid(LocalPlayerSubsystem))
	{
		LocalPlayerSubsystem->Username = "";
		LocalPlayerSubsystem->Password = "";
		LocalPlayerSubsystem->Email = "";
	}
	APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (IsValid(LocalPlayerController))
	{
		if (IHUDManagement* HUDManagementInterface = Cast<IHUDManagement>(LocalPlayerController->GetHUD()))
		{
			HUDManagementInterface->OnSignOut();
		}
	}
	

}
