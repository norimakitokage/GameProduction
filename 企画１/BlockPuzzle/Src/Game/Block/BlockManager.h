#pragma once
#include <Dxlib.h>
#include <vector>
#include "Block.h"

constexpr int BLOCK_ANIM_NUM = 1;

const int ARRAY_SIZE = 10;

using namespace std;

class CBlockManager
{
private:
	// ブロックの画像
	int m_BlockHndl;			

	// ブロックが壊れるときのアニメーション画像
	int m_BlockAnimHndl[BLOCK_ANIM_NUM];	

	// ブロックが置かれていないときの画像
	int m_BlockBgHndl;	

	// ブロックの座標
	vector<vector<CBlock>> m_Block;


public:
	void Init();
	void Load();
	void Step();
	void Exit();
	void Draw();

public:
	vector<vector<CBlock>> GetBlockVector();

};
