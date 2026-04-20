#pragma once
#include <DxLib.h>

//ボタンの名前
enum tagMouseInput {
	MOUSE1,
	MOUSE2,
	MOUSE3,
	MOUSE4,
	MOUSE5,
	MOUSE6,
	MOUSE7,
	MOUSE8,

	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_MID,

	MOUSE_NUM,
};

static const unsigned int MOUSE_BUTTON[] = {
	MOUSE_INPUT_1,
	MOUSE_INPUT_2,
	MOUSE_INPUT_3,
	MOUSE_INPUT_4,
	MOUSE_INPUT_5,
	MOUSE_INPUT_6,
	MOUSE_INPUT_7,
	MOUSE_INPUT_8,
	MOUSE_INPUT_LEFT,
	MOUSE_INPUT_RIGHT,
	MOUSE_INPUT_MIDDLE,
};


//マウスクラス
class CMouse
{
private:
	static int m_mouseX, m_mouseY;			//マウス座標
	static int m_mouseInput;				//マウスの押されたボタン
	static int m_mousePrevInput;			//マウスの前フレーム情報
	static int m_wheelRot;					//マウスホイール

	static int m_mouseButton[MOUSE_NUM];		//マウスのボタン情報
public:
	CMouse();
	~CMouse();
	static void Update();						//更新
	static bool Rep(unsigned int mouse);		//通常入力
	static bool Trg(unsigned int mouse);		//トリガー入力
	static bool Release(unsigned int mouse);	//入力されていない

	static int Button(tagMouseInput button);

	//座標の取得
	static void GetPos(int& mouseX, int& mouseY) {
		mouseX = m_mouseX;
		mouseY = m_mouseY;
	}

	//マウスホイールの回転量取得
	static void GetWheelRot(int& rot) { m_wheelRot; }
};


