#include "CameraManager.h"
#include "../../lib/controll/keyboard/key.h"
#include "../../lib/controll/mouse/mouse.h"
#include "../../lib/controll/pad/pad.h"
#include "../../common.h"
//#include <math.h>

//ーーーーーーーーーーーーーーーーーーーーーー
//スタティック変数を使えるように宣言
//ーーーーーーーーーーーーーーーーーーーーーー

//CCameraManager* CCameraManager::m_instance = nullptr;/

//ーーーーーーーーーーーーーーーーーーーーーー

const float CAMERA_FAR = 10000.0f;
const VECTOR START_CAM_POS = { 0.0f,0.0f,0.0f };
const VECTOR START_FORCUS = { 0.0f,0.0f,0.0f };
const VECTOR START_UPVEC = { 0.0f,1.0f,0.0f };

CCameraManager::CCameraManager() {
	//マウスのカメラからスタート
	m_id = ID_PLAY;
}

CCameraManager::~CCameraManager() {
}

// インスタンス取得関数
//CCameraManager* CCameraManager::GetInstance() {
//	if (m_instance == nullptr) {
//		m_instance = new CCameraManager();
//	}
//	return m_instance;
//}

// インスタンスを削除
//void CCameraManager::DeleteInstance() {
//	if (m_instance != nullptr) {
//		delete m_instance;
//		m_instance = nullptr;
//	}
//}

//初期化
void CCameraManager::Init() {
	m_id = ID_PLAY;
	
	SetCameraNearFar(1.0f, CAMERA_FAR);
	
	m_playerCamera.Init();

	m_debugCamera.Init();
}

// カメラの座標計算
void CCameraManager::Step(VECTOR forcusPosition){
#ifdef DEBUG
	if (CKey::Rep(KEY_INPUT_B) || CMouse::Rep(MOUSE_INPUT_MIDDLE)
		|| CPad::Rep(PAD_NUMBER[0], PAD_RIGHT_THUMB)) {
		switch (m_id)
		{
		case CCameraManager::ID_PLAY:
			m_id = ID_DEBUG;
			break;
		case CCameraManager::ID_DEBUG:
			m_id = ID_PLAY;
			break;
		}
	}
#endif // DEBUG

	
	
	switch (m_id)
	{
	case CCameraManager::ID_PLAY:
		m_playerCamera.Step(forcusPosition);
		break;
	case CCameraManager::ID_DEBUG:
		m_debugCamera.Step();
		break;
	}
}

//カメラの座標更新処理
void CCameraManager::Update() {
	switch (m_id)
	{
	case CCameraManager::ID_PLAY:
		m_playerCamera.Update();
		break;
	case CCameraManager::ID_DEBUG:
		m_debugCamera.Update();
		break;
	}
}



//カメラのY座標を取得
float CCameraManager::GetCamRotY() {
	switch (m_id)
	{
	case ID_PLAY:
		return m_playerCamera.GetCameraRotY();
		break;
	case ID_DEBUG:
		return m_debugCamera.GetCameraRotY();
		break;
	}
	return 0.0f;
}

//カメラの回転を取得
VECTOR CCameraManager::GetCamRot() {
	switch (m_id)
	{
	case CCameraManager::ID_PLAY:
		break;
	}
	// 返せなかった時は0を送る
	return VGet(0.0f, 0.0f, 0.0f);
}

VECTOR CCameraManager::GetCamPos() {
	switch (m_id)
	{
	case CCameraManager::ID_PLAY:
		return m_playerCamera.GetCameraPos();
		break;
	case CCameraManager::ID_DEBUG:
		return m_debugCamera.GetCameraPos();
		break;
	}
	// 返せなかった時は0を送る
	return VGet(0.0f, 0.0f, 0.0f);
}


