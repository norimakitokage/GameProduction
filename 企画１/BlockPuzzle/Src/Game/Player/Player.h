#pragma once
#include <DxLib.h>

enum tagPlayerState 
{
	PLAYER_CHOOSE,
	PLAYER_Drag,

	PLAYER_NUM
};

class CPlayer
{
private:
	int m_X;	// プレイヤーX座標
	int m_Y;	// プレイヤーY座標

	tagPlayerState m_state;

public:
	void Init();
	void Load();
	void Step();
	void Exit();
	void Draw();

public:
	int GetX();
	int GetY();


};
