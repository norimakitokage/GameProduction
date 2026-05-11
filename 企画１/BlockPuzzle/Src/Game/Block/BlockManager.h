#pragma once
#include <Dxlib.h>
#include <vector>
#include "../../Common.h"
#include "Block.h"
#include "RandomBlock.h"


using namespace std;

// ブロックのアニメーション数
constexpr int BLOCK_ANIM_NUM = 1;

// 配列の大きさ
const int ARRAY_SIZE = 10;

// ブロックの大きさ
const int BLOCK_SIZE = (int)(WINDOW_SIZE_Y * 0.1);
// ブロックの半分の大きさ
const int BLOCK_HALF = (int)(BLOCK_SIZE * 0.5f);

// 設置するブロックの選択肢の数
const int CHOISE_NUM = 3;

// 最初の位置
const int RANDOM_BLOCK_X = (WINDOW_SIZE_X / 4) * 3;
const int RANDOM_BLOCK_Y[CHOISE_NUM] = {
	WINDOW_SIZE_Y / 4,
	RANDOM_BLOCK_Y[0] * 2,
	RANDOM_BLOCK_Y[0] * 3,
};
// 枠の半径
const int RANDOM_BLOCK_RADIUS = RANDOM_BLOCK_Y[0] / 2;


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


	// 設置するブロック
	vector<CRandBlock> m_RBlock;
	int m_RBlockHndl[tagRandBlockType::NUMBER];
	

public:
	void Init();
	void Load();
	void Step(int x, int y);
	void Exit();
	void Draw();

public:
	vector<vector<CBlock>>* GetBlockVector();

	vector<CRandBlock>* GetRBlockVector();

	// RBlockの状態遷移をセット
	void SetRBlockState(int num, tagRandState state);
	
	// 縦横がブロックで埋まったかを確認 
	void Check();
};

