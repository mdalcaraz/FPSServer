#include "UI/HTTP/HTTPRequestTypes.h"
#include "DedicatedServers/DedicatedServers.h"

namespace HTTPStatusMessages
{ 
	const FString SomethingWentWrong{TEXT("Something went wrong!")};
}

void FDSMetaData::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("MetaData:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("httpStatusCode: %d"), httpStatusCode);
	UE_LOG(LogDedicatedServers, Log, TEXT("requestId: %s"), *requestId);
	UE_LOG(LogDedicatedServers, Log, TEXT("attemps: %d"), attemps);
	UE_LOG(LogDedicatedServers, Log, TEXT("totalRetryDelay: %f"), totalRetryDelay);
}

void FDSListFleetsResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("ListFleets response:"));
	for (const FString& FleetId : FleetIds)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("FleetIds: %s"), *FleetId);
	}
	if (!NextToken.IsEmpty())
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("NextToken: %s"), *NextToken);
	}
}

void FDSGameSession::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("GameSession:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("  CreationTime: %s"), *CreationTime);
	UE_LOG(LogDedicatedServers, Log, TEXT("  CreatorId: %s"), *CreatorId);
	UE_LOG(LogDedicatedServers, Log, TEXT("  CurrentPlayerSessionCount: %d"), CurrentPlayerSessionCount);
	UE_LOG(LogDedicatedServers, Log, TEXT("  DnsName: %s"), *DnsName);
	UE_LOG(LogDedicatedServers, Log, TEXT("  FleetArn: %s"), *FleetArn);
	UE_LOG(LogDedicatedServers, Log, TEXT("  FleetId: %s"), *FleetId);
	UE_LOG(LogDedicatedServers, Log, TEXT("  GameProperties:"));
	for (const auto& GameProperty : GameProperties)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("    %s: %s"), *GameProperty.Key, *GameProperty.Value);
	}

	UE_LOG(LogDedicatedServers, Log, TEXT("  GameSessionData: %s"), *GameSessionData);
	UE_LOG(LogDedicatedServers, Log, TEXT("  GameSessionId: %s"), *GameSessionId);
	UE_LOG(LogDedicatedServers, Log, TEXT("  IpAddress: %s"), *IpAddress);
	UE_LOG(LogDedicatedServers, Log, TEXT("  Location: %s"), *Location);
	UE_LOG(LogDedicatedServers, Log, TEXT("  MatchmakerData: %s"), *MatchmakerData);
	UE_LOG(LogDedicatedServers, Log, TEXT("  MaximumPlayerSessionCount: %d"), MaximumPlayerSessionCount);
	UE_LOG(LogDedicatedServers, Log, TEXT("  Name: %s"), *Name);
	UE_LOG(LogDedicatedServers, Log, TEXT("  PlayerSessionCreationPolicy: %s"), *PlayerSessionCreationPolicy);
	UE_LOG(LogDedicatedServers, Log, TEXT("  Port: %d"), Port);
	UE_LOG(LogDedicatedServers, Log, TEXT("  Status: %s"), *Status);
	UE_LOG(LogDedicatedServers, Log, TEXT("  StatusReason: %s"), *StatusReason);
	UE_LOG(LogDedicatedServers, Log, TEXT("  TerminationTime: %s"), *TerminationTime);
}

void FDSPlayerSession::Dump() const
{
	UE_LOG(LogTemp, Log, TEXT("FDSPlayerSession Dump:"));
	UE_LOG(LogTemp, Log, TEXT("  CreationTime: %s"), *CreationTime);
	UE_LOG(LogTemp, Log, TEXT("  DnsName: %s"), *DnsName);
	UE_LOG(LogTemp, Log, TEXT("  FleetArn: %s"), *FleetArn);
	UE_LOG(LogTemp, Log, TEXT("  FleetId: %s"), *FleetId);
	UE_LOG(LogTemp, Log, TEXT("  GameSessionId: %s"), *GameSessionId);
	UE_LOG(LogTemp, Log, TEXT("  IpAddress: %s"), *IpAddress);
	UE_LOG(LogTemp, Log, TEXT("  PlayerData: %s"), *PlayerData);
	UE_LOG(LogTemp, Log, TEXT("  PlayerId: %s"), *PlayerId);
	UE_LOG(LogTemp, Log, TEXT("  PlayerSessionId: %s"), *PlayerSessionId);
	UE_LOG(LogTemp, Log, TEXT("  Port: %d"), Port);
	UE_LOG(LogTemp, Log, TEXT("  Status: %s"), *Status);
	UE_LOG(LogTemp, Log, TEXT("  TerminationTime: %s"), *TerminationTime);
}

void FDSCodeDeliveryDetails::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("CodeDeliveryDetails:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   AttributeName: %s"), *AttributeName);
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeliveryMedium: %s"), *DeliveryMedium);
	UE_LOG(LogDedicatedServers, Log, TEXT("   Destination: %s"), *Destination);
}

void FDSSignUpResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSSignUpResponse Details:"));
	CodeDeliveryDetails.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("UserConfirmed: %s"), UserConfirmed ? TEXT("true") : TEXT("false"));
	UE_LOG(LogDedicatedServers, Log, TEXT("UserSub: %s"), *UserSub);
}

void FDSNewDeviceMetaData::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("NewDeviceMetadata:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeviceGroupKey: %s"), *DeviceGroupKey);
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeviceKey: %s"), *DeviceKey);
}
void FDSAuthenticationResult::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("AuthenticationResult:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   AccessToken: %s"), *AccessToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("   ExpiresIn: %d"), ExpiresIn);
	UE_LOG(LogDedicatedServers, Log, TEXT("   IdToken: %s"), *IdToken);
	NewDeviceMetadata.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("   RefreshToken: %s"), *RefreshToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("   TokenType: %s"), *TokenType);
}
void FDSChallengeParameters::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("ChallengeParameters:"));
	for (const auto& Param : Parameters)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("   %s: %s"), *Param.Key, *Param.Value);
	}
}
void FDSInitiateAuthResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSSignUpResponse Details:"));
	AuthenticationResult.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("ChallengeName: %s"), *ChallengeName);
	ChallengeParameters.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("Session: %s"), *Session);
	UE_LOG(LogDedicatedServers, Log, TEXT("email: %s"), *email);
}

void FDSRetrieveMatchStatsResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("highestStreak: %d"), highestStreak);
	UE_LOG(LogDedicatedServers, Log, TEXT("showStopperElims: %d"), showStopperElims);
	UE_LOG(LogDedicatedServers, Log, TEXT("dethroneElims: %d"), dethroneElims);
	UE_LOG(LogDedicatedServers, Log, TEXT("gotFirstBlood: %d"), gotFirstBlood);
	UE_LOG(LogDedicatedServers, Log, TEXT("defeats: %d"), defeats);
	UE_LOG(LogDedicatedServers, Log, TEXT("scoredElims: %d"), scoredElims);
	UE_LOG(LogDedicatedServers, Log, TEXT("email: %s"), *email);
	UE_LOG(LogDedicatedServers, Log, TEXT("misses: %d"), misses);
	UE_LOG(LogDedicatedServers, Log, TEXT("revengeElims: %d"), revengeElims);
	UE_LOG(LogDedicatedServers, Log, TEXT("matchLosses: %d"), matchLosses);
	UE_LOG(LogDedicatedServers, Log, TEXT("databaseid: %s"), *databaseid);
	UE_LOG(LogDedicatedServers, Log, TEXT("headShotElims: %d"), headShotElims);
	UE_LOG(LogDedicatedServers, Log, TEXT("username: %s"), *username);
	UE_LOG(LogDedicatedServers, Log, TEXT("hits: %d"), hits);
	UE_LOG(LogDedicatedServers, Log, TEXT("matchWins: %d"), matchWins);
}
