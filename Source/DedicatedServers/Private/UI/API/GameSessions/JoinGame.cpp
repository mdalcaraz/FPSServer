// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/API/GameSessions/JoinGame.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UJoinGame::SetStatusMessage(const FString& Message, bool bShouldResetWidget)
{
	TextBlock_StatusMessage->SetText(FText::FromString(Message));
	if (bShouldResetWidget)
	{
		Button_JoinGame->SetIsEnabled(true);
	}
}
