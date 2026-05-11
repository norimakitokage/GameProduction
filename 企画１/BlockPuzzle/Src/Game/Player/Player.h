#pragma once
#include <DxLib.h>
#include "../Block/RandomBlock.h"

class CPlayer
{
private:
	int m_X;	// プレイヤーX座標
	int m_Y;	// プレイヤーY座標

	bool m_IsCarry;	// プレイヤーが選択中かどうか
	int m_CarryNum;	// 動かしてるブロックの配列番号
	

public:
	void Init();
	void Load();
	void Step();
	void Exit();
	void Draw();

public:
	int GetX();
	int GetY();

	// 移動中かどうかのフラグオン
	void IsCarryOn();
	// 移動中かどうかのフラグオフ
	void IsCarryOff();
	// 移動中かどうかのフラグ取得
	bool GetIsCarry();

	// 移動中のブロック番号セット
	void SetCarryNum(int i);
	// 移動中のブロック番号ゲット
	int GetCarryNum();
};
