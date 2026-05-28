#include "BlockManager.h"
#include "../../Common.h"
#include "../../Lib/Admin/Data.h"
#include "../System/UI/UI.h"

const char* BLOCK_ANIM_PATH[BLOCK_ANIM_NUM] = {
	"",
	
};

const char* RANDOM_BLOCK_PATH[tagRandBlockType::NUMBER] = {
	"Data/Graph/1.png",
	"Data/Graph/2_hori.png",
	"Data/Graph/2_ver.png",
	"Data/Graph/3_hori.png",
	"Data/Graph/3_ver.png",
	"Data/Graph/4_hori.png",
	"Data/Graph/4_ver.png",
	"Data/Graph/5_hori.png",
	"Data/Graph/5_ver.png",
	"Data/Graph/3_up_left.png",
	"Data/Graph/3_up_right.png",
	"Data/Graph/3_down_right.png",
	"Data/Graph/3_down_left.png",
	"Data/Graph/5_up_left.png",
	"Data/Graph/5_up_right.png",
	"Data/Graph/5_down_right.png",
	"Data/Graph/5_down_left.png",
	"Data/Graph/9.png",
};





void CBlockManager::Init()
{
	m_Block.clear();
	// ブロック配列の設定
	m_Block.resize(ARRAY_SIZE, vector<CBlock>(ARRAY_SIZE));

	// 配列の大きさ設定
	m_RBlock.resize(CHOISE_NUM);

	// ブロックの座標設定
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int l = 0; l < ARRAY_SIZE; l++) {
			int x = i * BLOCK_SIZE + BLOCK_HALF;
			int y = l * BLOCK_SIZE + BLOCK_HALF;
			m_Block[i][l].Init(x, y);
		}
	}

	for (int i = 0; i < CHOISE_NUM; i++) {
		m_RBlock[i].Init();
	}

	m_BlockHndl = -1;
	m_BlockBgHndl = -1;
	for (int i = 0; i < BLOCK_ANIM_NUM; i++) {
		m_BlockAnimHndl[i] = -1;
	}

	for (int i = 0; i < tagRandBlockType::NUMBER; i++) {
		m_RBlockHndl[i] = -1;
	}
}

void CBlockManager::Load()
{
	for (int i = 0; i < BLOCK_ANIM_NUM; i++) {
		if (m_BlockAnimHndl[i] == -1) {
			m_BlockAnimHndl[i] = LoadGraph(BLOCK_ANIM_PATH[i]);
		}
	}

	if (m_BlockHndl == -1) {
		m_BlockHndl = LoadGraph("Data/Graph/Block.png");
	}

	if (m_BlockBgHndl == -1) {
		m_BlockBgHndl = LoadGraph("Data/Graph/BLOCK_NONE.png");
	}

	for (int i = 0; i < tagRandBlockType::NUMBER; i++) {
		m_RBlockHndl[i] = LoadGraph(RANDOM_BLOCK_PATH[i]);
	}
}

void CBlockManager::Step(int x, int y)
{
	for (auto iterator : m_RBlock) {
		iterator.Step(x, y);
	}

	bool flag = true;

	for (int i = 0; i < CHOISE_NUM; i++) {
		m_RBlock[i].Step(x, y);
		if (m_RBlock[i].GetState() != DONE) {
			flag = false;
		}
	}
	if (flag == true) {
		for (int i = 0; i < CHOISE_NUM; i++) {
			m_RBlock[i].Calc();
		}
	}

}

void CBlockManager::Exit()
{
	for (int i = 0; i < BLOCK_ANIM_NUM; i++) {
		if (m_BlockAnimHndl[i] != -1) {
			DeleteGraph(m_BlockAnimHndl[i]);
		}
	}

	if (m_BlockHndl != -1) {
		DeleteGraph(m_BlockHndl);
	}

	if (m_BlockBgHndl != -1) {
		DeleteGraph(m_BlockBgHndl);
	}

	m_Block.clear();
	m_RBlock.clear();
}

void CBlockManager::Draw()
{
	if (m_Block.empty()) return;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int l = 0; l < ARRAY_SIZE; l++) {
			VECTOR pos = m_Block[i][l].GetPosition();
			int left, right, up, down;
			left = pos.x - BLOCK_HALF;
			right = pos.x + BLOCK_HALF;
			up = pos.y - BLOCK_HALF;
			down = pos.y + BLOCK_HALF;


			DrawModiGraph(left, up, right, up, right, down, left, down, m_BlockBgHndl, TRUE);

			//DrawBox(left, up, right, down, WHITE, FALSE);
			
			if (m_Block[i][l].GetFlag()) {
				DrawModiGraph(left, up, right, up, right, down, left, down, m_BlockHndl, TRUE);
			}
		}
	}

	for (int i = 0; i < CHOISE_NUM; i++) {
		DrawBox(RANDOM_BLOCK_X - RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] - RANDOM_BLOCK_RADIUS,
			RANDOM_BLOCK_X + RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] + RANDOM_BLOCK_RADIUS, WHITE, FALSE);
		if (m_RBlock[i].GetState() == WAIT) {
			DrawModiGraph(RANDOM_BLOCK_X - RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] - RANDOM_BLOCK_RADIUS,
				RANDOM_BLOCK_X + RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] - RANDOM_BLOCK_RADIUS,
				RANDOM_BLOCK_X + RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] + RANDOM_BLOCK_RADIUS,
				RANDOM_BLOCK_X - RANDOM_BLOCK_RADIUS, RANDOM_BLOCK_Y[i] + RANDOM_BLOCK_RADIUS,
				m_RBlockHndl[m_RBlock[i].GetType()], TRUE);
		}
		else if(m_RBlock[i].GetState() == CARRY) {
			m_RBlock[i].Draw(m_BlockHndl);
		}
	}

}

void CBlockManager::Check()
{
	// 縦方向を表す
	const int ver = 0;
	// 横方向を表す
	const int hori = 1;

	int combo = 0;
	int score = 0;
	bool check = true;

	vector<vector<int>> mem;
	mem.clear();

	// 縦方向の確認
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int l = 0; l < ARRAY_SIZE; l++) {
			if (!m_Block[i][l].GetFlag()) {
				check = false;
			}
		}
		if (check) {
			mem.push_back({ ver, i });
		}
		else {
			check = true;
		}
	}
	// 横方向の確認
	for (int l = 0; l < ARRAY_SIZE; l++) {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			if (!m_Block[i][l].GetFlag()) {
				check = false;
			}
		}
		if (check) {
			mem.push_back({ hori, l });
		}
		else {
			check = true;
		}
	}

	for (int i = 0; i < mem.size(); ++i) {
		int type = mem[i][0];	// 縦横判断
		int mat = mem[i][1];	// 行列

		if (type == hori) {
			for (int n = 0; n < ARRAY_SIZE; n++) {
				m_Block[n][mat].FlagOFF();
			}
		}
		else if (type == ver) {
			for (int n = 0; n < ARRAY_SIZE; n++) {
				m_Block[mat][n].FlagOFF();
			}
		}

		combo += 1;
		score += ARRAY_SIZE;
	}
	mem.clear();

	CData* data = CData::GetInstance();
	data->AddScore(score * combo);
	if (combo > 1) {
		CUI::Request(combo);
	}
}

bool CBlockManager::IsContinue()
{
	int count = 0;

	for (int i = 0; i < CHOISE_NUM; i++) {
		// 設置済みだったら無視する
		if (m_RBlock[i].GetState() == tagRandState::DONE) {
			count++;
			continue;
		}

		for (int x = 0; x < ARRAY_SIZE; x++) {
			for (int y = 0; y < ARRAY_SIZE; y++) {
				switch (m_RBlock[i].GetType())
				{
					// 1ブロック
				case TYPE_1:
					if (!m_Block[x][y].GetFlag()) {
						return true;
					}
					break;

					// 2ブロック(横)
				case TYPE_2:
					if (x >= ARRAY_SIZE - 1) continue;
					if (!m_Block[x][y].GetFlag() && !m_Block[x + 1][y].GetFlag()) {
						return true;
					}
					break;

					// 2ブロック(縦)
				case TYPE_3:
					if (y <= 0) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x][y - 1].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(横)
				case TYPE_4:
					// 配列の大きさ確認
					if (x <= 1 || x >= ARRAY_SIZE - 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x + 1][y].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(縦)
				case TYPE_5:
					// 配列の大きさ確認
					if (y <= 0 || y >= ARRAY_SIZE - 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x][y - 1].GetFlag() && !m_Block[x][y + 1].GetFlag()) {
						return true;
					}
					break;

					// 4ブロック(横)
				case TYPE_6:
					// 配列の大きさ確認
					if (x <= 0 || x >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x + 1][y].GetFlag()
						&& !m_Block[x + 2][y].GetFlag()){
						return true;
					}
					break;

					// 4ブロック(縦)
				case TYPE_7:
					// 配列の大きさ確認
					if (y <= 0 || y >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x][y - 1].GetFlag() && !m_Block[x][y + 1].GetFlag()
						&& !m_Block[x][y + 2].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(横)
				case TYPE_8:
					// 配列の大きさ確認
					if (x <= 1 || x >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x - 2][y].GetFlag()
						&& !m_Block[x + 1][y].GetFlag() && !m_Block[x + 2][y].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(縦)
				case TYPE_9:
					// 配列の大きさ確認
					if (y <= 1 || y >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x][y - 1].GetFlag() && !m_Block[x][y - 2].GetFlag()
						&& !m_Block[x][y + 1].GetFlag() && !m_Block[x][y + 2].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(左上)
				case TYPE_10:
					// 配列の大きさ確認
					if (x <= 0 || y <= 0) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x][y - 1].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(右上)
				case TYPE_11:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 1 || y <= 0) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x + 1][y].GetFlag() && !m_Block[x][y - 1].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(右下)
				case TYPE_12:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 1 || y >= ARRAY_SIZE - 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x + 1][y].GetFlag() && !m_Block[x][y + 1].GetFlag()) {
						return true;
					}
					break;

					// 3ブロック(左下)
				case TYPE_13:
					// 配列の大きさ確認
					if (x <= 0 || y >= ARRAY_SIZE - 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x][y + 1].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(左上)
				case TYPE_14:
					// 配列の大きさ確認
					if (x <= 1 || y <= 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x - 2][y].GetFlag()
						&& !m_Block[x][y - 1].GetFlag() && !m_Block[x][y - 2].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(右上)
				case TYPE_15:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 2 || y <= 1) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x + 1][y].GetFlag() && !m_Block[x + 2][y].GetFlag()
						&& !m_Block[x][y - 1].GetFlag() && !m_Block[x][y - 2].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(右下)
				case TYPE_16:
					// 配列の大きさ確認
					if (x >= ARRAY_SIZE - 2 || y >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x + 1][y].GetFlag() && !m_Block[x + 2][y].GetFlag()
						&& !m_Block[x][y + 1].GetFlag() && !m_Block[x][y + 2].GetFlag()) {
						return true;
					}
					break;

					// 5ブロック(左下)
				case TYPE_17:
					// 配列の大きさ確認
					if (x <= 1 || y >= ARRAY_SIZE - 2) continue;
					// まだ置かれていないなら
					if (!m_Block[x][y].GetFlag() && !m_Block[x - 1][y].GetFlag() && !m_Block[x - 2][y].GetFlag()
						&& !m_Block[x][y + 1].GetFlag() && !m_Block[x][y + 2].GetFlag()) {
						return true;
					}
					break;

					// 9ブロック(正方形)
				case TYPE_18:
					// 配列の大きさ確認
					if (x <= 0 || x >= ARRAY_SIZE - 1 || y <= 0 || y >= ARRAY_SIZE - 1) continue;
					// まだ置かれていないなら設置
					if (!m_Block[x][y].GetFlag() && !m_Block[x][y - 1].GetFlag() && !m_Block[x][y + 1].GetFlag()
						&& !m_Block[x - 1][y].GetFlag() && !m_Block[x - 1][y - 1].GetFlag() && !m_Block[x - 1][y + 1].GetFlag()
						&& !m_Block[x + 1][y].GetFlag() && !m_Block[x + 1][y - 1].GetFlag() && !m_Block[x + 1][y + 1].GetFlag()) {
						return true;
					}
					break;
				}
			}
		}
	}

	if (count >= CHOISE_NUM) {
		return true;
	}
	else {
		return false;
	}
}

vector<vector<CBlock>>* CBlockManager::GetBlockVector()
{
	return &m_Block;
}

vector<CRandBlock>* CBlockManager::GetRBlockVector()
{
	return &m_RBlock;
}

void CBlockManager::SetRBlockState(int num, tagRandState state)
{
	m_RBlock[num].SetState(state);
}
