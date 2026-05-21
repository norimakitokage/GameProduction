#include "HitCheck.h"
#include "../../Lib/Collision/Collision.h"

using namespace std;

bool CHitCheck::PlayerToBlock(CPlayer& player, CBlockManager& block)
{
	vector<vector<CBlock>>& bl = *block.GetBlockVector();
	vector<CRandBlock>& rbl = *block.GetRBlockVector();
	VECTOR plPos;
	plPos.x = (float)player.GetX();
	plPos.y = (float)player.GetY();
	plPos.z = 0.0f;

	for (int x = 0; x < ARRAY_SIZE; x++) {
		for (int y = 0; y < ARRAY_SIZE; y++) {
			VECTOR pos;
			pos = bl[x][y].GetPosition();
			bool flag = CColl::DotToSquare(plPos, pos, BLOCK_SIZE, BLOCK_SIZE);
			if (flag) {
				tagRandBlockType type = rbl[player.GetCarryNum()].GetType();
				switch (type)
				{
				case TYPE_1:
					if (!bl[x][y].GetFlag()) {
						bl[x][y].FlagOn();
						player.IsCarryOff();
						return true;
					}
					else return false;
					break;
				case TYPE_2:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x + 1][y].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x + 1][y].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_3:
					// 配列の大きさ確認
					if (y <= 0) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x][y - 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x][y - 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_4:
					// 配列の大きさ確認
					if (x <= 0 || x >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x + 1][y].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x + 1][y].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_5:
					// 配列の大きさ確認
					if (y <= 0 || y >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x][y - 1].GetFlag() && !bl[x][y + 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y + 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_6:
					// 配列の大きさ確認
					if (x <= 0 || x >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x + 1][y].GetFlag() 
						&& !bl[x + 2][y].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x + 2][y].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_7:
					// 配列の大きさ確認
					if (y <= 0 || y >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x][y - 1].GetFlag() && !bl[x][y + 1].GetFlag()
						&& !bl[x][y + 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y + 1].FlagOn();
						bl[x][y + 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_8:
					// 配列の大きさ確認
					if (x <= 1 || x >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x - 2][y].GetFlag()
						&& !bl[x + 1][y].GetFlag() && !bl[x + 2][y].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x - 2][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x + 2][y].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_9:
					// 配列の大きさ確認
					if (y <= 1 || y >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x][y - 1].GetFlag() && !bl[x][y - 2].GetFlag()
						&& !bl[x][y + 1].GetFlag() && !bl[x][y + 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y - 2].FlagOn();
						bl[x][y + 1].FlagOn();
						bl[x][y + 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_10:
					// 配列の大きさ確認
					if (x <= 0 || y <= 0) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x][y - 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x][y - 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_11:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 1 || y <= 0) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x + 1][y].GetFlag() && !bl[x][y - 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x][y - 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_12:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 1 || y >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x + 1][y].GetFlag() && !bl[x][y + 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x][y + 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_13:
					// 配列の大きさ確認
					if (x <= 0 || y >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x][y + 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x][y + 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_14:
					// 配列の大きさ確認
					if (x <= 1 || y <= 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x - 2][y].GetFlag()
						&& !bl[x][y - 1].GetFlag() && !bl[x][y - 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x - 2][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y - 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_15:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 2 || y <= 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x + 1][y].GetFlag() && !bl[x + 2][y].GetFlag()
						&& !bl[x][y - 1].GetFlag() && !bl[x][y - 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x + 2][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y - 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_16:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 2 || y >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x + 1][y].GetFlag() && !bl[x + 2][y].GetFlag()
						&& !bl[x][y + 1].GetFlag() && !bl[x][y + 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x + 2][y].FlagOn();
						bl[x][y + 1].FlagOn();
						bl[x][y + 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_17:
					// 配列の大きさ確認
					if (x <= 0 || y >= ARRAY_SIZE - 2) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x - 1][y].GetFlag() && !bl[x - 2][y].GetFlag()
						&& !bl[x][y + 1].GetFlag() && !bl[x][y + 2].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x - 2][y].FlagOn();
						bl[x][y + 1].FlagOn();
						bl[x][y + 2].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				case TYPE_18:
					// 配列の大きさ確認
					if (x <= 0 || x >= ARRAY_SIZE - 1 || y <= 0 || y >= ARRAY_SIZE - 1) {
						return false;
					}
					// まだ置かれていないなら設置
					if (!bl[x][y].GetFlag() && !bl[x][y - 1].GetFlag() && !bl[x][y + 1].GetFlag()
						&& !bl[x - 1][y].GetFlag() && !bl[x - 1][y - 1].GetFlag() && !bl[x - 1][y + 1].GetFlag()
						&& !bl[x + 1][y].GetFlag() && !bl[x + 1][y - 1].GetFlag() && !bl[x + 1][y + 1].GetFlag()) {
						bl[x][y].FlagOn();
						bl[x][y - 1].FlagOn();
						bl[x][y + 1].FlagOn();
						bl[x - 1][y].FlagOn();
						bl[x - 1][y - 1].FlagOn();
						bl[x - 1][y + 1].FlagOn();
						bl[x + 1][y].FlagOn();
						bl[x + 1][y - 1].FlagOn();
						bl[x + 1][y + 1].FlagOn();
						player.IsCarryOff();
						return true;
					}
					break;
				}
			}
		}
	}

}

void CHitCheck::PlayerToRandomBlock(CPlayer& player, CBlockManager& block)
{
	int X = player.GetX();
	int Y = player.GetY();
	int num = -1;
	vector<CRandBlock>& bl = *block.GetRBlockVector();

	for (int i = 0; i < CHOISE_NUM; i++) {
		bool flag = CColl::DotToSquare(VGet(X, Y, 0.0f), VGet(RANDOM_BLOCK_X, RANDOM_BLOCK_Y[i],0.0f),
			RANDOM_BLOCK_RADIUS * 2, RANDOM_BLOCK_RADIUS * 2);
		if (flag == true) {
			// プレイヤーとヒットした番号保存
			num = i;
			player.SetCarryNum(num);
			player.IsCarryOn();
			break;
		}
	}
	if (num != -1) {
		bl[num].SetState(CARRY);
	}	
}
