#pragma once
#include "../../Lib/Collision/Collision.h"
#include "../Block/BlockManager.h"
#include "../Player/Player.h"

class CHitCheck
{
public:
	static void PlayerToBlock(CPlayer &player, CBlockManager &block);

};