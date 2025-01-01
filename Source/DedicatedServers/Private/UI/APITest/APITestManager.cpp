// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/APITest/APITestManager.h"
#include "Data/API/APIData.h"
#include "HttpModule.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Interfaces/IHttpResponse.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "JsonObjectConverter.h"


void UAPITestManager::ListFleets()
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UAPITestManager::ListFleets_Response);
	const FString APIUrl = APIData->GetAPIEndpoint(DedicatedServersTags::GameSessionsAPI::ListFleets);
	Request->SetURL(APIUrl);
	Request->SetVerb(TEXT("GET"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("apllication/json"));
	Request->ProcessRequest();
}

void UAPITestManager::ListFleets_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "List fleets Response received");

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsError(JsonObject))
		{
			OnListFleetsResponseReceived.Broadcast(FDSListFleetsResponse(), false);
			return;
		}
		DumpMetaData(JsonObject);

		FDSListFleetsResponse ListFleetsResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &ListFleetsResponse);
		ListFleetsResponse.Dump();
		OnListFleetsResponseReceived.Broadcast(ListFleetsResponse, true);

	}
}
