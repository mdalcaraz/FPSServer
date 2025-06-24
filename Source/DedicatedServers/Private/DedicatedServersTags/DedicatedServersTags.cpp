#include "GameplayTags/DedicatedServersTags.h"


namespace DedicatedServersTags
{
	namespace GameSessionsAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ListFleets, "DedicatedServersTags.GameSessionsAPI.ListFleets", "List Fleets resource on the GameSessions API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(FindOrCreateGameSessions, "DedicatedServersTags.GameSessionsAPI.FindOrCreateGameSessions", "Retrieves an ACTIVE Game session, creating one if one doesn't exist on the GameSessions API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(CreatePlayerSession, "DedicatedServersTags.GameSessionsAPI.CreatePlayerSession", "Create a new Player Session on the GameSession API");
	}
	namespace PortalAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SignUp, "DedicatedServersTags.PortalAPI.SignUp", "Creates a new User in the Portal API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConfirmSignUp, "DedicatedServersTags.PortalAPI.ConfirmSignUp", "Confirms a new user in Portal API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SignIn, "DedicatedServersTags.PortalAPI.SignIn", "Retrieves Access Token, Id Token, and Refresh Token in Portal API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SignOut, "DedicatedServersTags.PortalAPI.SignOut", "Sign users out and invalidates tokens in Portal API");

	}

	namespace GameStatsAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(RecordMatchStats, "DedicatedServersTags.GameStatsAPI.RecordMatchStats", "Records the states of a mach in Game Stats");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(RetrieveMatchStats, "DedicatedServersTags.GameStatsAPI.RetrieveMatchStats", "Gets the match stats from the table in game stats APÏ");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(UpdateLeaderboard, "DedicatedServersTags.GameStatsAPI.UpdateLeaderboard", "Update Leaderboards in game stats APÏ");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(RetrieveLeaderboard, "DedicatedServersTags.GameStatsAPI.RetrieveLeaderboard", "Retrieves Leaderboards in game stats APÏ");
	}
}