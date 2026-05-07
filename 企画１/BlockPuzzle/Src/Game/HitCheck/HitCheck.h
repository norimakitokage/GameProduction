#pragma once
#include "../Block/BlockManager.h"
#include "../Player/Player.h"

class CHitCheck
{
public:
	static void PlayerToBlock(CPlayer &player, CBlockManager &block);

	static void PlayerToRandomBlock(CPlayer& player, CBlockManager& block);

};