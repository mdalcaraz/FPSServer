// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"
#include "UI/Portal/PortalManager.h"

void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();

	check(PortalManagerClass);
	check(IsValid(JoinGamewidget));
	check(IsValid(JoinGamewidget->Button_JoinGame));

	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);

	JoinGamewidget->Button_JoinGame->OnClicked.AddDynamic(this, &USignInOverlay::OnJoinGameButtonClicked);
}

void USignInOverlay::OnJoinGameButtonClicked()
{
	check(IsValid(PortalManager));
	check(IsValid(JoinGamewidget));
	check(IsValid(JoinGamewidget->Button_JoinGame));

	PortalManager->BroadcastJoinGameSessionMessage.AddDynamic(this, &USignInOverlay::UpdateJoinGameStatusMessage);
	PortalManager->JoinGameSession();

	JoinGamewidget->Button_JoinGame->SetIsEnabled(false);
}

void USignInOverlay::UpdateJoinGameStatusMessage(const FString& StatusMessage, bool bResetJoinGameButton)
{
	check(IsValid(JoinGamewidget));
	check(IsValid(JoinGamewidget->Button_JoinGame));

	JoinGamewidget->SetStatusMessage(StatusMessage);

	if (bResetJoinGameButton)
	{
		JoinGamewidget->Button_JoinGame->SetIsEnabled(true);
	}
}
