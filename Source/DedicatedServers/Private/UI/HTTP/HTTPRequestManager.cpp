// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HTTP/HTTPRequestManager.h"
#include "DedicatedServers/DedicatedServers.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "JsonObjectConverter.h"



bool UHTTPRequestManager::ContainsError(TSharedPtr<FJsonObject> JsonObject)
{
	if (JsonObject->HasField(TEXT("errorType")) || JsonObject->HasField(TEXT("errorMessage")))
	{
		FString ErrorType = JsonObject->HasField(TEXT("errorType")) ? JsonObject->GetStringField(TEXT("errorType")) : TEXT("Uknown Error");
		FString ErrorMessage = JsonObject->HasField(TEXT("errorMessage")) ? JsonObject->GetStringField(TEXT("errorMessage")) : TEXT("Uknown Error Message");

		UE_LOG(LogDedicatedServers, Error, TEXT("Error Typee %s"), *ErrorType);
		UE_LOG(LogDedicatedServers, Error, TEXT("Error Message %s"), *ErrorMessage);

		return true;
	}
	if (JsonObject->HasField(TEXT("$fault")))
	{
		FString ErrorType = JsonObject->HasField(TEXT("name")) ? JsonObject->GetStringField(TEXT("name")) : TEXT("Uknown Error");
		UE_LOG(LogDedicatedServers, Error, TEXT("Error Typee %s"), *ErrorType);

		return true;
	}
	return false;
}

void UHTTPRequestManager::DumpMetaData(TSharedPtr<FJsonObject> JsonObject)
{
	if (JsonObject->HasField(TEXT("$metadata")))
	{
		TSharedPtr<FJsonObject> MetaDataJsonObject = JsonObject->GetObjectField(TEXT("$metadata"));
		FDSMetaData DSMetaData;
		FJsonObjectConverter::JsonObjectToUStruct(MetaDataJsonObject.ToSharedRef(), &DSMetaData);

		DSMetaData.Dump();
	}
}
