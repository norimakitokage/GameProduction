#include "cameraDebug.h"
#include <math.h>
#include "../../../common.h"


static const float CAMERA_SPEED = 1.0f;
static const float CAMERA_ROT_SPEED = 0.02f;

CDebugCamera::CDebugCamera() {
	memset(&m_camPos, 0, sizeof(VECTOR));
	memset(&m_camRot, 0, sizeof(VECTOR));
}

void CDebugCamera::Init() {
	m_camPos = VGet(0.0f, 0.0f, 1.0f);
	m_camRot = VGet(0.0f, 0.0f, 0.0f);
}

void CDebugCamera::Init(VECTOR vPos, VECTOR vForcus, VECTOR vUp) {
	m_camPos = vPos;
}

void CDebugCamera::SetNearFar(float fNear, float fFar) {
	SetCameraNearFar(fNear, fFar);
}

void CDebugCamera::Step() {
	//カメラの計算
	VECTOR vcamPos = VGet(0.0f, 0.0f, 0.0f);

	//視点移動
	if (CheckHitKey(KEY_INPUT_UP)) {
		m_camRot.x -= CAMERA_ROT_SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) {
		m_camRot.x += CAMERA_ROT_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		m_camRot.y -= CAMERA_ROT_SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		m_camRot.y += CAMERA_ROT_SPEED;
	}

	//カメラの移動処理
	//前進
	if (CheckHitKey(KEY_INPUT_W)) {
		//最初に移動値を設定
		VECTOR defaultDir = { 0.0f, 0.0f, CAMERA_SPEED };
		//計算
		m_camPos = VAdd(m_camPos, Move(defaultDir));
	}
	else if (CheckHitKey(KEY_INPUT_S)) {
		VECTOR defaultDir = { 0.0f,0.0f,-CAMERA_SPEED };
		m_camPos = VAdd(m_camPos, Move(defaultDir));
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		VECTOR defaultDir = { CAMERA_SPEED,0.0f,0.0f };
		m_camPos = VAdd(m_camPos, Move(defaultDir));
	}
	else if (CheckHitKey(KEY_INPUT_A)) {
		VECTOR defaultDir = { -CAMERA_SPEED,0.0f,0.0f };
		m_camPos = VAdd(m_camPos, Move(defaultDir));
	}


	//カメラの位置はプレイヤー＋計算結果
	m_camPos = VAdd(m_camPos, vcamPos);

}

void CDebugCamera::Update() {
	SetCameraPositionAndAngle(m_camPos,
		m_camRot.x, m_camRot.y, m_camRot.z);

#ifdef DEBUG
	DrawFormatString(20, 20, WHITE, "X : %2f  Y : %2f  Z : %2f", m_camPos.x,
		m_camPos.y, m_camPos.z);
#endif // DEBUG
}

VECTOR CDebugCamera::Move(VECTOR speed) {
	MATRIX dir = MGetTranslate(speed);
	//X軸回転行列
	MATRIX rotX = MGetRotX(m_camRot.x);
	//Y軸回転行列
	MATRIX rotY = MGetRotY(m_camRot.y);
	//各行列を合成していく
	MATRIX res = MMult(dir, rotX);		//最初に移動、その後回転
	res = MMult(res, rotY);

	//行列から移動情報だけを取り出す
	VECTOR move;
	move.x = res.m[3][0];
	move.y = res.m[3][1];	//DxLibの関数を使ったら、3行目に座標情報がでる
	move.z = res.m[3][2];

	return move;
}