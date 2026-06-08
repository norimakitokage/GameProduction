#include "Actor.h"

enum tagAnimLoop {
	ANIM_DEFAULT,
	ANIM_LOOP,
	ANIM_ENDLOOP,
};

//コンストラクタ
CActor::CActor() {
	Init();
}

//初期化
void CActor::Init() {
	//親クラスの変数を初期化
	CObject::Init();
	//m_animDataの中身を一旦全て0にする
	ZeroMemory(&m_animData, sizeof(m_animData));
	//初期値が-1のものだけ個別で初期化
	m_animData.m_hndl = -1;
	m_animData.m_id = -1;
	m_animData.m_isStop = false;
}

//更新処理
void CActor::Update() {
	//親クラスのUpdateを呼んでSRTを確定
	CObject::Update();

	//アニメーションの更新処理
	if (m_animData.m_hndl == -1) return;

	//フラグがONなら進めない
	if(!m_animData.m_isStop){
		//アニメーションの時間を進める
		m_animData.m_frame += m_animData.m_speed;
	}

	if (m_animData.m_frame >= m_animData.m_endFrame) {
		switch (m_animData.m_state)
		{
		case ANIM_DEFAULT:
			DetachAnim();
			m_animData.m_endFrame = 0.0f;
			m_animData.m_frame = 0.0f;
			m_animData.m_speed = 0.0f;
			break;
		case ANIM_LOOP:
			m_animData.m_frame = 0.0f;
			break;
		case ANIM_ENDLOOP:
			m_animData.m_frame = m_animData.m_endFrame;
			break;
		}
	}

	//アニメーションの時間を更新
	MV1SetAttachAnimTime(m_Hndl, m_animData.m_hndl, m_animData.m_frame);
}

//アニメリクエスト
void CActor::Request(int animId, float animSpd, int animSrcHndl, bool NameCheck) {
	DetachAnim();

	m_animData.m_hndl = MV1AttachAnim(m_Hndl, animId, animSrcHndl, NameCheck);
	m_animData.m_id = animId;
	m_animData.m_endFrame = MV1GetAnimTotalTime(m_Hndl, animId);
	m_animData.m_frame = 0.0f;
	m_animData.m_speed = animSpd;
	m_animData.m_state = ANIM_DEFAULT;
}

//ループアニメリクエスト
void CActor::RequestLoop(int animId, float animSpd, int animSrcHndl, bool NameCheck) {
	Request(animId, animSpd, animSrcHndl, NameCheck);
	//ここだけ変える
	m_animData.m_state = ANIM_LOOP;
}

//エンドループアニメリクエスト
void CActor::RequestEndLoop(int animId, float animSpd, int animSrcHndl, bool NameCheck) {
	Request(animId, animSpd, animSrcHndl, NameCheck);
	m_animData.m_state = ANIM_ENDLOOP;
}

//アニメーションを停止させる
void CActor::StopAnimation() {
	m_animData.m_isStop = true;
}

//アニメーションを再再生
void CActor::PlayAnimation() {
	m_animData.m_isStop = false;
}

//アニメーション速度を指定して再生
void CActor::PlayAnimation(float frame) {
	m_animData.m_isStop = false;
	m_animData.m_frame = frame;
}

//現在のアニメーション再生時間を取得
float CActor::GetAnimTime() {
	return m_animData.m_frame;
}

int CActor::GetAnimID() {
	return m_animData.m_id;
}

//アニメーションデタッチ
void CActor::DetachAnim() {
	if (m_animData.m_hndl != -1) {
		MV1DetachAnim(m_Hndl, m_animData.m_hndl);
		m_animData.m_hndl = -1;
	}
}

bool CActor::IsEndAnim() {
	if (m_animData.m_frame >= m_animData.m_endFrame) {
		return true;
	}
	else {
		return false;
	}
}

