// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameLiftServerSDK.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DS_GameInstanceSubsystems.generated.h"

struct FServerParameters;
/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UDS_GameInstanceSubsystems : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UDS_GameInstanceSubsystems();
	void InitGameLift(const FServerParameters& ServerParams);

	UPROPERTY(BlueprintReadOnly)
	bool bGameLiftInitialized;

private:
	FProcessParameters ProcessParams;
	void ParseCommandLinePort(int32& OutPort);

};
