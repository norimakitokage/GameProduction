#include "pad.h"
#include <math.h>

//スタティック変数呼び出し
int CPad::m_attachedNum;		
XINPUT_STATE CPad::m_pad[PAD_MAX_NUM];
XINPUT_STATE CPad::m_prevPad[PAD_MAX_NUM];

int TRIGGER_DEADZONE = 120;	//トリガーのデッドゾーン
int BUTTON_ON = 1;				//ボタンをオンにする
int BUTTON_OFF = 0;			//ボタンをオンにする

int THUMB_DEADZONE = 128;	//スティックのデッドゾーン

//コンストラクタ
CPad::CPad() {
	Init();
}

//デストラクタ
CPad::~CPad() {
	Exit();
}

void CPad::Init() {
	m_attachedNum = 0;
}

void CPad::Step() {
	m_attachedNum = GetJoypadNum();

	//パッドの最大数までループさせる
	for (int i = 0; i < m_attachedNum; i++) {
		//前の情報を保存
		m_prevPad[i] = m_pad[i];

		//パッド情報を取得
		GetJoypadXInputState(PAD_NUMBER[i], &m_pad[i]);

		//トリガーボタンのオンオフ確認
		if (m_pad[i].LeftTrigger >= TRIGGER_DEADZONE) {
			m_pad[i].Buttons[PAD_LEFT_TRIGGER] = BUTTON_ON;
		}
		else m_pad[i].Buttons[PAD_LEFT_TRIGGER] = BUTTON_OFF;

		if (m_pad[i].RightTrigger >= TRIGGER_DEADZONE) {
			m_pad[i].Buttons[PAD_RIGHT_TRIGGER] = BUTTON_ON;
		}
		else m_pad[i].Buttons[PAD_RIGHT_TRIGGER] = BUTTON_OFF;

	}
}

void CPad::Exit() {
	m_attachedNum = 0;
}

//通常入力
bool CPad::Rep(int pad_num, PAD_BUTTON button) {
	//ボタンがONかつ、前フレームで押されていなかったらtrueを返す
	if (m_pad[pad_num - 1].Buttons[button] == BUTTON_ON && 
		m_prevPad[pad_num - 1].Buttons[button] == BUTTON_OFF) {
		return true;
	}
	else return false;
}

//トリガー入力
bool CPad::Trg(int pad_num, PAD_BUTTON button) {
	//ボタンが押されていたらtrueを返す
	if (m_pad[pad_num - 1].Buttons[button] == BUTTON_ON) {
		return true;
	}
	else return false;
}

//左スティック入力
void CPad::LStick(int pad_num, int& x, int& y) {
	x = static_cast<int>(m_pad[pad_num - 1].ThumbLX);
	y = static_cast<int>(m_pad[pad_num - 1].ThumbLY);
}
//右スティック入力
void CPad::RStick(int pad_num, int& x, int& y) {
	x = static_cast<int>(m_pad[pad_num - 1].ThumbRX);
	y = static_cast<int>(m_pad[pad_num - 1].ThumbRY);
}

//左スティックの回転量
float CPad::LStickRot(int pad_num) {
	float atan = atan2f(m_pad[pad_num - 1].ThumbLY, m_pad[pad_num - 1].ThumbLX);

	return atan;
}
//右スティックの回転量
float CPad::RStickRot(int pad_num) {
	float atan = atan2f(m_pad[pad_num - 1].ThumbRY, m_pad[pad_num - 1].ThumbRX);
	return atan;
}

//左スティックのベクトル
void LStickRot(float& x, float& y, float& z) {

}

//右スティックのベクトル
void RStickRot(float& x, float& y, float& z) {

}

//
bool CPad::IsConnect() {
	if (m_attachedNum != 0) {
		return true;
	}
	return false;
}

bool CPad::None(int pad_num) {
	for (int i = 0; i < PAD_BUTTON::PAD_NUM; i++) {
		if (m_pad[pad_num - 1].Buttons[i] == 1) {
			return false;
		}
	}
	if (abs(m_pad[pad_num - 1].ThumbLX) < THUMB_DEADZONE
		&& abs(m_pad[pad_num - 1].ThumbLY) < THUMB_DEADZONE
		&& abs(m_pad[pad_num - 1].ThumbRX) < THUMB_DEADZONE
		&& abs(m_pad[pad_num - 1].ThumbRY) < THUMB_DEADZONE) {
		return true;
	}
	return false;
	
}


