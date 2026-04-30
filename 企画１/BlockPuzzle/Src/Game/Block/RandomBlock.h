#pragma once
#include <DxLib.h>
#include "../../Lib/Math/Getrand.h"

enum tagRandBlockType {
	// 1ブロック
	TYPE_1,
	// 2ブロック(横)
	TYPE_2,
	// 2ブロック(縦)
	TYPE_3,
	// 3ブロック(横)
	TYPE_4,
	// 3ブロック(縦)
	TYPE_5,
	// 4ブロック(横)
	TYPE_6,
	// 4ブロック(縦)
	TYPE_7,
	// 5ブロック(横)
	TYPE_8,
	// 5ブロック(縦)
	TYPE_9,
	// 3ブロック(左上)
	TYPE_10,
	// 3ブロック(右上)
	TYPE_11,
	// 3ブロック(右下)
	TYPE_12,
	// 3ブロック(左下)
	TYPE_13,
	// 5ブロック(左上)
	TYPE_14,
	// 5ブロック(右上)
	TYPE_15,
	// 5ブロック(右下)
	TYPE_16,
	// 5ブロック(左下)
	TYPE_17,
	// 9ブロック(正方形)
	TYPE_18,

	// 総種類
	NUMBER
};

enum tagRandState {
	WAIT,
	CARRY,
	NONE,

};

class CRandBlock 
{
private:
	tagRandBlockType m_Type;

	// ブロックの状態
	tagRandState m_State;

	// 設置されたか
	bool m_IsPut;

	// 座標
	int m_X;
	int m_Y;

public:
	void Init();
	//void Load();
	void Step(int x, int y);
	void Exit();
	void Draw(int hndl);

public:
	// 状態遷移をセット
	void SetState(tagRandState state);
	// 設置されたか確認
	bool GetIsPut();
	// 設置された時
	void IsPutOn();

private:
	tagRandBlockType Random();
};

