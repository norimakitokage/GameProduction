#include "SceneResualt.h"
#include "../../../Common.h"
#include "../../../Lib/Fade/Fade.h"
#include "../../../Lib/Controll/Mouse/Mouse.h"
#include "../../../Lib/Admin/Data.h"

CSceneResualt::CSceneResualt() {
	m_state = INIT;
}

CSceneResualt::~CSceneResualt() {
	Exit();
}

//ループ処理
int CSceneResualt::Loop() {

	void (CSceneResualt:: * scene[])() = { &CSceneResualt::Init, &CSceneResualt::Load, &CSceneResualt::StartWait,
	& CSceneResualt::Step, & CSceneResualt::EndWait, & CSceneResualt::Exit };

	(this->*scene[m_state])();

	//終わったかを外部に伝える
	return m_endingNum;
}

//描画
void CSceneResualt::Draw() {
	//DrawFormatString(20, 20, RED, "リザルトシーン");
	DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 1.0f, 0.0f, m_hndl, true);

	CData* data = CData::GetInstance();

	SetFontSize(64);
	DrawFormatString(WINDOW_SENTER_X * 0.5f, WINDOW_SENTER_Y - (64 * 2), WHITE, "SCORE");
	DrawFormatString(WINDOW_SENTER_X * 0.5f, WINDOW_SENTER_Y , WHITE, "%d", data->GetScore());
	SetFontSize(16);
}

//初期化
void CSceneResualt::Init() {
	m_endingNum = -1;
	m_memEnd = -1;

	m_hndl = -1;

	m_state = LOAD;
}

//読み込み
void CSceneResualt::Load() {

	if (m_hndl == -1) {
		m_hndl = LoadGraph("Data/Graph/res.jpg");
	}

	CFade::RequestFadeIn();		//フェードイン呼び出し
	m_state = STARTWAIT;		//スタート待機へ
}

//スタート待機
void CSceneResualt::StartWait() {
	if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
		m_state = MAIN;
	}
}

//更新処理
void CSceneResualt::Step() {
	if (CMouse::Trg(MOUSE_INPUT_LEFT)) {
		m_memEnd = 1;
		m_state = ENDWAIT;
		CFade::RequestFadeOut();
	}
}

//終了前処理
void CSceneResualt::EndWait() {
	if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
		m_state = END;
	}
}

//終了処理s
void CSceneResualt::Exit() {
	m_state = INIT;
	m_endingNum = m_memEnd;

	CData::DeleteInstance();

	if (m_hndl != -1) {
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}




