// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/GamePage.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"
#include "UI/GameSessions/GameSessionsManager.h"

void UGamePage::NativeConstruct()
{
	Super::NativeConstruct();

	GameSessionManager = NewObject<UGameSessionsManager>(this, GameSessionsManagerClass);
	GameSessionManager->BroadcastJoinGameSessionMessage.AddDynamic(JoingameWidget, &UJoinGame::SetStatusMessage);

	JoingameWidget->Button_JoinGame->OnClicked.AddDynamic(this, &UGamePage::JoinGameButtonclicked);
}

void UGamePage::JoinGameButtonclicked()
{
	JoingameWidget->Button_JoinGame->SetIsEnabled(false);
	GameSessionManager->JoinGameSession();
}
