#pragma once
#include <DxLib.h>

class CActorMove {
public:
	//アクターの移動量を計算する関数
	static VECTOR GetMoveVec(float rotY, float spd);
};

