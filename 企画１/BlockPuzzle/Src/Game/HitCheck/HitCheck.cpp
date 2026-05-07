#include "HitCheck.h"
#include "../../Lib/Collision/Collision.h"

using namespace std;

void CHitCheck::PlayerToBlock(CPlayer& player, CBlockManager& block)
{
	vector<vector<CBlock>>& bl = *block.GetBlockVector();

}

void CHitCheck::PlayerToRandomBlock(CPlayer& player, CBlockManager& block)
{
	int X = player.GetX();
	int Y = player.GetY();
	int num = -1;

	for (int i = 0; i < CHOISE_NUM; i++) {
		bool flag = CColl::DotToSquare(VGet(X, Y, 0.0f), VGet(RANDOM_BLOCK_X, RANDOM_BLOCK_Y[i],0.0f),
			RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_RADIUS);
		if (flag == true) {
			// プレイヤーとヒットした番号保存
			num = i;
			player.SetCarryNum(num);
			player.IsCarryOn();
			break;
		}
	}
	if (num != -1) {
		vector<CRandBlock>& bl = *block.GetRBlockVector();
		bl[num].SetState(CARRY);
	}	
}
