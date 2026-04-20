#include "sceneTitle.h"
#include "../../../Common.h"
#include "../../../Lib/Fade/Fade.h"
#include "../../../Lib/Controll/Mouse/Mouse.h"


CSceneTitle::CSceneTitle() {
	m_state = INIT;
}

CSceneTitle::~CSceneTitle() {
	Exit();
}

//ループ処理
int CSceneTitle::Loop() {

	void (CSceneTitle::*scene[])() = {&CSceneTitle::Init, &CSceneTitle::Load, &CSceneTitle::StartWait,
	&CSceneTitle::Step, &CSceneTitle::EndWait, &CSceneTitle::Exit };

	(this->*scene[m_state])();

	//終わったかを外部に伝える
	return m_endingNum;
}

//描画
void CSceneTitle::Draw() {
	DrawFormatString(20, 20, RED, "タイトルシーン");
	DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 1.0f, 0.0f, m_hndl, true);
}

//初期化
void CSceneTitle::Init() {
	m_endingNum = -1;
	m_memEnd = -1;
	
	m_state = LOAD;
}

//読み込み
void CSceneTitle::Load() {
	
	if (m_hndl == -1) {
		m_hndl = LoadGraph("");
	}

	CFade::RequestFadeIn();		//フェードイン呼び出し
	m_state = STARTWAIT;		//スタート待機へ
}

//スタート待機
void CSceneTitle::StartWait() {
	if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
		m_state = MAIN;
	}
}

//更新処理
void CSceneTitle::Step() {
	if (CMouse::Trg(MOUSE_INPUT_LEFT)) {
		m_memEnd = 1;
		m_state = ENDWAIT;
		CFade::RequestFadeOut();
	}
}

//終了前処理
void CSceneTitle::EndWait() {
	if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
		m_state = END;
	}
}

//終了処理
void CSceneTitle::Exit() {
	m_state = INIT;
	m_endingNum = m_memEnd;

	if (m_hndl != -1) {
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}



