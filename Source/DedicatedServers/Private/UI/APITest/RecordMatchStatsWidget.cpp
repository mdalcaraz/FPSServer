// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/APITest/RecordMatchStatsWidget.h"

#include "Components/Button.h"
#include "UI/GameStats/GameStatsManager.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "Player/DSLocalPlayerSubsystem.h"

void URecordMatchStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameStatsManager = NewObject<UGameStatsManager>(this, GameStatsManagerClass);
	Button_RecordMatchStats->OnClicked.AddDynamic(this, &URecordMatchStatsWidget::RecordMatchStatsButtonClicked);
	
}

void URecordMatchStatsWidget::RecordMatchStatsButtonClicked()
{
	check(GameStatsManager);
	UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetOwningLocalPlayer()->GetSubsystem<UDSLocalPlayerSubsystem>();
	if (!IsValid(LocalPlayerSubsystem)) return;

	const FString Username{TEXT("testuser1")};
	// const FString Username = LocalPlayerSubsystem->Username;

	FDSRecordMatchStatsInput RecordMatchStatsInput;
	RecordMatchStatsInput.username = Username;
	RecordMatchStatsInput.matchStats.hits = 1;
	RecordMatchStatsInput.matchStats.headShotElims = 5;

	GameStatsManager->RecordMatchStats(RecordMatchStatsInput);
}
