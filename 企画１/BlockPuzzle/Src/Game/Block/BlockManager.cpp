#include "BlockManager.h"
#include "../../Common.h"

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

// 最初の位置
const int RANDOM_BLOCK_X = (WINDOW_SIZE_X / 4) * 3;
const int RANDOM_BLOCK_Y[CHOISE_NUM] = {
	WINDOW_SIZE_Y / 4,
	RANDOM_BLOCK_Y[0] * 2,
	RANDOM_BLOCK_Y[0] * 3,
};
// 枠の半径
const int RANDOM_BLOCK_RADIUS = RANDOM_BLOCK_Y[0] / 2;



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
	}
}

vector<vector<CBlock>> CBlockManager::GetBlockVector()
{
	return m_Block;
}
