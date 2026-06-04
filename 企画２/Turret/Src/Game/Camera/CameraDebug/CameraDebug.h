#pragma once
#include <DxLib.h>

class CDebugCamera {
private:
	VECTOR m_camPos;		//カメラの位置
	VECTOR m_camRot;			//カメラの回転値
public:
	CDebugCamera();

	//初期化
	void Init();
	//継承した時用の初期化
	void Init(VECTOR vPos, VECTOR vForcus, VECTOR vUp);

	//ニアとファーをセット
	void SetNearFar(float fNear, float fFar);

	//カメラの座標計算
	//vForcus	:プレイヤーの座標
	//fRot		:プレイヤーの角度
	void Step();

	//計算データを反映
	void Update();

	VECTOR GetCameraPos() { return m_camPos; }
	float GetCameraRotY() { return m_camRot.y; }

	void SetCameraRot(float _rotY) { m_camRot.y = _rotY; }
	void SetCameraPos(VECTOR _pos) { m_camPos = _pos; }

private:
	VECTOR Move(VECTOR speed);

	
};
