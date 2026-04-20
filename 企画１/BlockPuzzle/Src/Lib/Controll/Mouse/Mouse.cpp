#include "mouse.h"
#include <DxLib.h>

int CMouse::m_mouseX, CMouse::m_mouseY;
int CMouse::m_mouseInput;
int CMouse::m_mousePrevInput;
int CMouse::m_wheelRot;

int CMouse::m_mouseButton[MOUSE_NUM];

//コンストラクタ
CMouse::CMouse() {
	m_mouseX = 0;
	m_mouseY = 0;
	m_mouseInput = 0;
	m_mousePrevInput = 0;
}

//デストラクタ
CMouse::~CMouse() {
	m_mouseX = 0;
	m_mouseY = 0;
	m_mouseInput = 0;
	m_mousePrevInput = 0;
}

//更新
void CMouse::Update() {
	//情報リセット
	m_mousePrevInput = m_mouseInput;
	m_mouseInput = 0;

	//マウスポインターの座標
	GetMousePoint(&m_mouseX, &m_mouseY);
	//現在押されているマウスの情報
	m_mouseInput = GetMouseInput();
	//マウスのホイール回転量
	m_wheelRot = GetMouseWheelRotVol();

	//入力されていない状態にする
	for (int i = 0; i < MOUSE_NUM; i++) {
		m_mouseButton[i] = -1;
	}

	//マウスのプッシュリリース情報を取得
	int ClickX, ClickY, Button, LogType;
	while (GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0) {
		for (int i = 0; i < MOUSE_NUM; i++) {
			if (MOUSE_BUTTON[i] & Button) {
				m_mouseButton[i] = LogType;
			}
		}
	}
}

//通常入力
bool CMouse::Rep(unsigned int mouse) {
	if ((m_mouseInput & mouse) && !(m_mousePrevInput & mouse))
	{
		return true;
	}
	return false;
}

//トリガー入力
bool CMouse::Trg(unsigned int mouse) {
	if ((m_mouseInput & mouse) && (m_mousePrevInput & mouse))
	{
		return true;
	}
	return false;
}

//入力されていない
bool CMouse::Release(unsigned int mouse) {
	if (!(m_mouseInput & mouse)) {
		return true;
	}
	return false;
}

int CMouse::Button(tagMouseInput button) {
	return m_mouseButton[button];
}



