#include "BlockManager.h"
#include "../../Common.h"

const char* BLOCK_ANIM_PATH[BLOCK_ANIM_NUM] = {
	"",
	
};

const int BLOCK_SIZE = (int)(WINDOW_SIZE_Y * 0.1);
const int BLOCK_HALF = (int)(BLOCK_SIZE * 0.5f);

void CBlockManager::Init()
{
	m_Block.clear();
	// ブロック配列の設定
	m_Block.resize(ARRAY_SIZE, vector<CBlock>(ARRAY_SIZE));

	// ブロックの座標設定
	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int l = 0; l < ARRAY_SIZE; l++) {
			int x = i * BLOCK_SIZE + BLOCK_HALF;
			int y = l * BLOCK_SIZE + BLOCK_HALF;
			m_Block[i][l].Init(x, y);
		}
	}

	m_Block[7][2].SetFlag(true);

	m_BlockHndl = -1;
	m_BlockBgHndl = -1;
	for (int i = 0; i < BLOCK_ANIM_NUM; i++) {
		m_BlockAnimHndl[i] = -1;
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
		m_BlockHndl = LoadGraph("");
	}

	if (m_BlockBgHndl == -1) {
		m_BlockBgHndl = LoadGraph("");
	}
}

void CBlockManager::Step()
{


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
			DrawBox(pos.x - BLOCK_HALF, pos.y - BLOCK_HALF, pos.x + BLOCK_HALF, pos.y + BLOCK_HALF, WHITE, FALSE);
			DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0.0f, m_BlockBgHndl, TRUE);
			if (m_Block[i][l].GetFlag()) {
				DrawBox(pos.x - BLOCK_HALF, pos.y - BLOCK_HALF, pos.x + BLOCK_HALF, pos.y + BLOCK_HALF, WHITE, TRUE);
				DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0.0f, m_BlockHndl, TRUE);
			}
		}
	}
}

vector<vector<CBlock>> CBlockManager::GetBlockVector()
{
	return m_Block;
}
