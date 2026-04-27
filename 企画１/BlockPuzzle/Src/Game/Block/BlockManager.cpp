#include "BlockManager.h"

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
}

vector<vector<CBlock>> CBlockManager::GetBlockVector()
{
	return m_Block;
}
