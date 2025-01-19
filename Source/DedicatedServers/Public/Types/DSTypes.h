#pragma once

#include "DSTypes.generated.h"

UENUM(BlueprintType)
enum class ECountdownTimerState : uint8
{
	NotStarted	UMETA(DisplayName = "Not Started"),
	Started		UMETA(DisplayName = "Started"),
	Paused		UMETA(DisplayName = "Paused"),
	Stopped		UMETA(DisplayName = "Stopped")
};

UENUM(BlueprintType)
enum class ECountdownTimerType : uint8
{
	LobbyCountdown UMETA(DisplayName = "Lobby Countdown"),
	PreMatch UMETA(DisplayName = "Pre Match"),
	Match UMETA(DisplayName = "Match"),
	PostMatch UMETA(DisplayName = "Post Match"),
	None UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType)
struct FCountdownTimerHandle
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	ECountdownTimerState State = ECountdownTimerState::NotStarted;

	UPROPERTY(BlueprintReadWrite)
	ECountdownTimerType Type = ECountdownTimerType::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CountdownTime = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CountdownUpdateInterval = 1.f;

	FTimerHandle TimerFinishHandle{};
	FTimerHandle TimerUpdateHandle{};
	FTimerDelegate TimerFinishDelegate{};
	FTimerDelegate TimerUpdateDelegate{};

};

inline bool operator==(const FCountdownTimerHandle& lhs, const FCountdownTimerHandle& rhs)
{
	return lhs.Type == rhs.Type;
}