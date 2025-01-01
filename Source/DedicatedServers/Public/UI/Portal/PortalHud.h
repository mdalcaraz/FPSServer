// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PortalHud.generated.h"

class USignInOverlay;
/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API APortalHud : public AHUD
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USignInOverlay> SignInOverlayClass;

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY()
	TObjectPtr<USignInOverlay> SignInOverlay;
	
	
	
};
