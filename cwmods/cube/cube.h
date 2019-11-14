#ifndef CUBE_H
#define CUBE_H
#include "../cwmods.h"
#include "../steam/ISteamNetworking.h"
#include "../steam/ISteamUser.h"

// For data which must be gotten from cube world by offset

namespace cube {
	class Game;
	cube::Game* GetGame();
	ID3D11Device* GetID3D11Device();
	ID3D11DeviceContext* GetID3D11DeviceContext();

	void* GetSteamNetworkingContext();
	void* GetSteamUserContext();
	void* SteamInternal_ContextInit(void* context);
	ISteamNetworking* SteamNetworking();
	ISteamUser* SteamUser();
}

#endif // CUBE_H
