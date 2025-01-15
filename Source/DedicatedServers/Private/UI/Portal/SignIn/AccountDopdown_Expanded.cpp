// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/AccountDopdown_Expanded.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "UI/Portal/PortalManager.h"
#include "Player/DSLocalPlayerSubsystem.h"

void UAccountDopdown_Expanded::NativeConstruct()
{
	Super::NativeConstruct();

	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	Button_SignOut->OnClicked.AddDynamic(this, &UAccountDopdown_Expanded::SignOutButton_OnClicked);
	Button_SignOut->OnHovered.AddDynamic(this, &UAccountDopdown_Expanded::SignOutButton_Hover);
	Button_SignOut->OnUnhovered.AddDynamic(this, &UAccountDopdown_Expanded::SignOutButton_Unhover);

	UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetLocalPlayerSubsystem();
	if (IsValid(LocalPlayerSubsystem))
	{
		TextBlock_Email->SetText(FText::FromString(LocalPlayerSubsystem->Email));
	}
}

void UAccountDopdown_Expanded::NativePreConstruct()
{
	Super::NativePreConstruct();

	SignOutButton_Unhover();
	SetSignOutButtonStyleTransparent();
}

void UAccountDopdown_Expanded::SignOutButton_Hover()
{
	TextBlock_SignOutButtonText->SetColorAndOpacity(HoveredTextColor);
}

void UAccountDopdown_Expanded::SignOutButton_Unhover()
{
	TextBlock_SignOutButtonText->SetColorAndOpacity(UnhoveredTextColor);
}

void UAccountDopdown_Expanded::SignOutButton_OnClicked()
{
	Button_SignOut->SetIsEnabled(false);

	check(PortalManager);
	UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetLocalPlayerSubsystem();
	if (IsValid(LocalPlayerSubsystem))
	{
		FDSAuthenticationResult AuthResult = LocalPlayerSubsystem->GetAuthResult();
		PortalManager->SignOut(AuthResult.AccessToken);
	}
}

void UAccountDopdown_Expanded::SetSignOutButtonStyleTransparent()
{
	FButtonStyle Style;
	FSlateBrush Brush;
	Brush.TintColor = FSlateColor(FLinearColor(0.f, 0.f, 0.f, 0.f));
	Style.Disabled = Brush;
	Style.Hovered = Brush;
	Style.Pressed = Brush;
	Style.Normal = Brush;
	Button_SignOut->SetStyle(Style);
}

UDSLocalPlayerSubsystem* UAccountDopdown_Expanded::GetLocalPlayerSubsystem()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (IsValid(PlayerController) && IsValid(PlayerController->GetLocalPlayer()))
	{
		UDSLocalPlayerSubsystem* LocalPlayerSubsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UDSLocalPlayerSubsystem>();
		if (IsValid(LocalPlayerSubsystem))
		{
			return LocalPlayerSubsystem;
		}
	}
	return nullptr;
}
