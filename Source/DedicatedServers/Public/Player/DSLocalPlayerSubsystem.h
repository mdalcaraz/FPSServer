// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "DSLocalPlayerSubsystem.generated.h"

class UPortalManager;
class IPortalManagement;
/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UDSLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	
	void InitializeTokens(const FDSAuthenticationResult& AuthResult, TScriptInterface<IPortalManagement> PortalManagement);
	void UpdateTokens(const FString& AccessToken, const FString& IdToken);
	void SetRefreshTokenTimer();
private:
	UPROPERTY()
	FDSAuthenticationResult	AuthenticationResult;
	
	UPROPERTY()
	TScriptInterface<IPortalManagement> PortalManagementInterface;

	float TokenRefreshInterval = 2700.f; // 75% of an hour (Expiration time)
	FTimerHandle RefreshTimer;
};
