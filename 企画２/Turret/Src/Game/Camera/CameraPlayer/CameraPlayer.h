#pragma once
#include <DxLib.h>

class CPlayerCamera {
private:
	VECTOR m_CamPos;		//カメラの位置
	VECTOR m_TargetPos;		//カメラの注視点
	VECTOR m_UpVec;			//カメラの上方向
	VECTOR m_CamRot;		//カメラの回転
public:
	CPlayerCamera();
	~CPlayerCamera();

	//初期化
	void Init();

	//カメラの座標計算
	//vForcus	:プレイヤーの座標
	//fRot		:プレイヤーの角度
	void Step(VECTOR vForcus);

	// カメラ座標の更新
	void Update();

	//--------------------------------------------
	//				ゲッター
	//--------------------------------------------
	//カメラの位置を取得
	VECTOR GetCameraPos() { return m_CamPos; }
	//カメラの回転量ゲット
	VECTOR GetCameraRot() { return m_CamRot; }
	//カメラのY軸回転ゲット
	float GetCameraRotY() { return m_CamRot.y; }
	//カメラの注視点
	VECTOR GetFocus() { return m_TargetPos; }

	//--------------------------------------------
	//				セッター
	//--------------------------------------------
	void SetCameraPos(VECTOR pos) { m_CamPos = pos; }
	void SetCameraRot(VECTOR rot) { m_CamRot = rot; }

private:
	//画面の外に出たか確認
	bool MousePointCheck();
};