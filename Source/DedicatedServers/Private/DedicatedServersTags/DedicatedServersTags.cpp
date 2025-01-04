#include "GameplayTags/DedicatedServersTags.h"


namespace DedicatedServersTags
{
	namespace GameSessionsAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ListFleets, "DedicatedServersTags.GameSessionsAPI.ListFleets", "List Fleets resource on the GameSessions API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(FindOrCreateGameSessions, "DedicatedServersTags.GameSessionsAPI.FindOrCreateGameSessions", "Retrieves an ACTIVE Game session, creating one if one doesn't exist on the GameSessions API");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(CreatePlayerSession, "DedicatedServersTags.GameSessionsAPI.CreatePlayerSession", "Create a new Player Session on the GameSession API");
	}
}