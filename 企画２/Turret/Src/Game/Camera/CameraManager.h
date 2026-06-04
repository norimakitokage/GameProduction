#pragma once
#include <DxLib.h>
#include "CameraPlayer/CameraPlayer.h"
#include "CameraDebug/CameraDebug.h"

//複数のカメラを管理する
class CCameraManager {
public:
	enum tagCameraID {
		ID_PLAY,			// 自分で視点操作するカメラ
		ID_DEBUG,			// デバッグ用のカメラの

		ID_NUM
	};
private:

	//static CCameraManager* m_instance;
	
	tagCameraID m_id;				//今どのカメラを使っているか
	tagCameraID m_prevId;			//前のカメラID
	tagCameraID m_nextId;			//次のカメラID

	CPlayerCamera m_playerCamera;

	CDebugCamera m_debugCamera;

public:
	CCameraManager();
	~CCameraManager();

	//CCameraManager* GetInstance();
	//void DeleteInstance();
	
	//初期化
	void Init();

	//カメラの座標計算
	void Step(VECTOR forcusPosition);

	// カメラの位置情報更新
	void Update();


	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	//					ゲッター
	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

	//カメラのタイプ取得
	

	//カメラの回転を取得
	float GetCamRotY();
	VECTOR GetCamRot();
	VECTOR GetCamPos();
	
};