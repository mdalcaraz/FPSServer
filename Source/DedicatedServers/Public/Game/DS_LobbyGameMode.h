// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DS_GameModeBase.h"
#include "GameLiftServerSDK.h"
#include "DS_LobbyGameMode.generated.h"

class UDS_GameInstanceSubsystems;
/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ADS_LobbyGameMode : public ADS_GameModeBase
{
	GENERATED_BODY()

public:
	ADS_LobbyGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	void CheckAndStartLobbyCountdown();

protected:
	virtual void BeginPlay() override;
	virtual void OnCountdownTimerFinished(ECountdownTimerType Type) override;
	virtual void InitSeamlessTravelPlayer(AController* NewController) override;
	void CheckAndStopLobbyCountdown();
	virtual void Logout(AController* Exiting) override;
	
	UPROPERTY()
	ELobbyStatus LobbyStatus;

	UPROPERTY(EditDefaultsOnly)
	int32 MinPlayers;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> DestinationMap;
private:
	UPROPERTY()
	TObjectPtr<UDS_GameInstanceSubsystems> DSGameInstanceSubsystem;

	UPROPERTY(EditDefaultsOnly)
	FCountdownTimerHandle LobbyCountdownTimer;
	
	void InitGameLift();
	void SetServerParameters(FServerParameters& OutServerParameters);
};
