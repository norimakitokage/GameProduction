#include <math.h>
#include "cameraPlayer.h"
#include "../../../common.h"
#include "../../../lib/controll/mouse/mouse.h"
#include "../../../lib/controll/pad/pad.h"

//カメラ関連
const float CAMERA_LENGTH = 10.0f;		//カメラとプレイヤーの距離
const float CAMERA_HIGH = 5.0f;			//カメラの高さ
const float CAMERA_TARGET_HIGH = 2.5f;	//注視点の高さ

//マウスのスピード、大きいほど遅くなる
const int MOUSE_SPEED_X = 1000;
const int MOUSE_SPEED_Y = 2000;

//コントローラーのスピード
const int PAD_SPEED_X = 600;
const int PAD_SPEED_Y = 600;

//カメラの上下移動上限
const float CAMERA_ROLL_MAX = 0.5f;
const float CAMERA_ROLL_MIN = -1.0f;

//カメラの初期位置
const float CAMERA_START_YAW = 2.65f;
const float CAMERA_START_ROLL = -0.7f;
const float CAMERA_POSY_MIN = 0.0f;


CPlayerCamera::CPlayerCamera() {
	memset(&m_CamPos, 0, sizeof(VECTOR));
	memset(&m_TargetPos, 0, sizeof(VECTOR));
	memset(&m_UpVec, 0, sizeof(VECTOR));
	memset(&m_CamRot, 0, sizeof(VECTOR));
}

CPlayerCamera::~CPlayerCamera() {
}

void CPlayerCamera::Init() {
	m_CamPos = VGet(0.0f, 0.0f, 0.0f);
	m_TargetPos = VGet(0.0f, 0.0f, 0.0f);
	m_UpVec = VGet(0.0f, 1.0f, 0.0f);
	m_CamRot = VGet(CAMERA_START_ROLL, CAMERA_START_YAW, 0.0f);
}

void CPlayerCamera::Step(VECTOR vForcus){
	//各種定義関連
	const float MAX_LEN_NEAR = 50.0f;
	const float MAX_LEN_FAR = 60.0f;
	const float MIN_LEN_NEAR = 40.0f;
	const float MIN_LEN_FAR = 30.0f;
	const float CAM_MOVE_SPEED = 0.5f;

	int X, Y = 0;

	//マウスの座標を取得
	if (!CPad::IsConnect()) {
		CMouse::GetPos(X, Y);
		SetMousePoint(WINDOW_SENTER_X, WINDOW_SENTER_Y);
		X = X - WINDOW_SENTER_X;
		Y = Y - WINDOW_SENTER_Y;
	}
	else {
		CPad::RStick(PAD_NUMBER[0], X, Y);
		X = X / PAD_SPEED_X;
		Y = Y / PAD_SPEED_Y;
		if (abs(X) < 1) { X = 0; }
		if (abs(Y) < 1) { Y = 0; }
	}

	//マウスの移動距離をロットに変換
	m_CamRot.y += X / static_cast<float>(MOUSE_SPEED_X);
	m_CamRot.x += Y / static_cast<float>(-MOUSE_SPEED_Y);

	if (m_CamRot.x >= CAMERA_ROLL_MAX) m_CamRot.x = CAMERA_ROLL_MAX;
	else if (m_CamRot.x <= CAMERA_ROLL_MIN) m_CamRot.x = CAMERA_ROLL_MIN;

	//計算したカメラの座標
	VECTOR camPos = VGet(0.0f, 0.0f, 0.0f);

	//座標を計算
	camPos.x = sinf(m_CamRot.y) * CAMERA_LENGTH;
	camPos.y = tanf(m_CamRot.x) * -CAMERA_HIGH;
	camPos.z = cosf(m_CamRot.y) * CAMERA_LENGTH;

	////方向ベクトルの取得
	//VECTOR dir = VSub(m_CamPos, vForcus);
	////方向ベクトルの長さを求める
	//float len = VSize(dir);
	////一定以上距離が離れたら
	//if (len >= MAX_LEN_NEAR) {
	//	//座標を計算
	//	camPos.x = sinf(m_CamRot.y) * MAX_LEN_NEAR;
	//	camPos.y = tanf(m_CamRot.x) * -CAMERA_HIGH;
	//	camPos.z = cosf(m_CamRot.y) * MAX_LEN_NEAR;
	//	//移動ベクトルを座標に
	//	camPos = VAdd(camPos, m_CamRot);

	//	//方向ベクトルの取得
	//	VECTOR tempDir = VSub(m_CamPos, camPos);
	//	tempDir = VNorm(tempDir);
	//	//動かしたいスピード分掛け算する
	//	tempDir = VScale(tempDir, CAM_MOVE_SPEED);
	//	m_CamPos = VAdd(m_CamPos, tempDir);

	//	if (VSquareSize(tempDir) > MAX_LEN_FAR * MAX_LEN_FAR) {
	//		tempDir = VNorm(tempDir);
	//		tempDir = VScale(tempDir, MAX_LEN_FAR);
	//		m_CamPos = VAdd(vForcus, tempDir);
	//	}
	//}
	//else if (len < MIN_LEN_NEAR) {
	//	//座標を計算
	//	camPos.x = sinf(m_CamRot.y) * MIN_LEN_NEAR;
	//	camPos.y = tanf(m_CamRot.x) * -CAMERA_HIGH;
	//	camPos.z = cosf(m_CamRot.y) * MIN_LEN_NEAR;
	//	//移動ベクトルを座標に
	//	camPos = VAdd(camPos, m_CamPos);

	//	//方向ベクトルの取得
	//	VECTOR tempDir = VSub(m_CamPos, camPos);
	//	tempDir = VNorm(tempDir);
	//	//動かしたいスピード分掛け算する
	//	tempDir = VScale(tempDir, CAM_MOVE_SPEED);
	//	m_CamPos = VAdd(m_CamPos, tempDir);

	//	if (VSquareSize(tempDir) > MIN_LEN_FAR * MIN_LEN_FAR) {
	//		tempDir = VNorm(tempDir);
	//		tempDir = VScale(tempDir, MIN_LEN_FAR);
	//		m_CamPos = VAdd(vForcus, tempDir);
	//	}
	//}

	//カメラの位置はプレイヤー＋計算結果
	m_CamPos = VAdd(vForcus, camPos);

	if (m_CamPos.y <= CAMERA_POSY_MIN) m_CamPos.y = CAMERA_POSY_MIN;
 
	//カメラの位置を設定
	m_TargetPos = vForcus;
	m_TargetPos.y += CAMERA_TARGET_HIGH;
}

void CPlayerCamera::Update() {
	SetCameraPositionAndTargetAndUpVec(m_CamPos, m_TargetPos, m_UpVec);
}



bool CPlayerCamera::MousePointCheck() {
	int x, y;
	CMouse::GetPos(x, y);
	if (x > WINDOW_SIZE_X || x < 0 ||
		y > WINDOW_SIZE_Y || y < 0) {
		return true;
	}
	
	return false;
}
