#pragma once
#include <Dxlib.h>
#include "../Observer/Observer.h"

constexpr int BLOCK_WIDE = 20;

class CBlock : public CObserver
{
protected:
	// 中心座標
	VECTOR m_Center;	

	// 生存フラグ
	// @true  ブロックが置かれた状態
	// @false ブロックが置かれてない
	bool m_Flag;

	// アニメーション時のカウント
	int m_Count;
	// アニメーションのフラグ
	bool m_AnimFlag;

public:

	void Init(int X, int Y);

	void Step();

	void Update();

public:
	// 中心座標取得
	VECTOR GetPosition();

	// 生存フラグ取得
	bool GetFlag();

	// 生存フラグのセット
	void SetFlagOn();

};

