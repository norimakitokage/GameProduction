#include "key.h"
#include <DxLib.h>

char CKey::buf[BUFF_MAX];
char CKey::prevBuf[BUFF_MAX];

const int KEY_ON = 1;	//キーボードが押されている
const int KEY_OFF = 0;	//キーボードが押されていない

//初期化
void CKey::Init() {
	for (int i = 0; i < BUFF_MAX; i++) {
		buf[i] = NULL;
		prevBuf[i] = NULL;
	}
}

//更新
void CKey::Step() {
	for (int i = 0; i < BUFF_MAX; i++) {
		prevBuf[i] = buf[i];
	}

	GetHitKeyStateAll(buf);
}

//通常入力
bool CKey::Rep(int key) {
	//新しく入力されたらtrueを返す
	if (buf[key] == KEY_ON && prevBuf[key] == KEY_OFF) {
		return true;
	}
	else return false;
}

//トリガー入力
bool CKey::Trg(int key) {
	//前キーと同じだったらtrueを返す
	if (prevBuf[key] == KEY_ON && buf[key] == KEY_ON) {
		return true;
	}
	else return false;
}

//何も押されていないか確認
bool CKey::None() {
	for (int i = 0; i < BUFF_MAX; i++) {
		if (buf[i] == KEY_ON) {
			return false;
		}
	}
	return true;
}

