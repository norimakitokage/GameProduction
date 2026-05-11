#include "SceneGame.h"
#include "../../../Common.h"
#include "../../../Lib/Fade/Fade.h"
#include "../../../Lib/Controll/Mouse/Mouse.h"
#include "../../HitCheck/HitCheck.h"


CSceneGame::CSceneGame() {
	m_State = INIT;

}

CSceneGame::~CSceneGame() {
	Exit();
}

//ループ処理
int CSceneGame::Loop() {

	void (CSceneGame:: * scene[])() = { &CSceneGame::Init, &CSceneGame::Load, &CSceneGame::StartWait,
	& CSceneGame::Step, & CSceneGame::EndWait, & CSceneGame::Exit };

	(this->*scene[m_State])();

	//終わったかを外部に伝える
	return m_EndingNum;
}

//描画
void CSceneGame::Draw() {
	//DrawFormatString(20, 20, RED, "プレイシーン");

	m_Block.Draw();
	
}

//初期化
void CSceneGame::Init() {
	m_EndingNum = -1;
	m_MemEnd = -1;

	m_Block.Init();

	m_Player.Init();

	m_State = LOAD;
}

//読み込み
void CSceneGame::Load() {
	
	m_Block.Load();

	CFade::RequestFadeIn();		//フェードイン呼び出し
	m_State = STARTWAIT;		//スタート待機へ
}

//スタート待機
void CSceneGame::StartWait() {
	if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
		m_State = MAIN;
	}
}

//更新処理
void CSceneGame::Step() {
	m_Player.Step();

	m_Block.Step(m_Player.GetX(), m_Player.GetY());

	if (CMouse::Rep(MOUSE_INPUT_LEFT)) {
		// ブロックを持ち上げる処理
		if (!m_Player.GetIsCarry()) {
			CHitCheck::PlayerToRandomBlock(m_Player, m_Block);
		}
		// ブロックを設置する処理
		else {
			bool res = CHitCheck::PlayerToBlock(m_Player, m_Block);
			if (res == true) {
				m_Block.SetRBlockState(m_Player.GetCarryNum(), DONE);
				m_Block.Check();
			}
		}
	}

	// ブロックを手放す処理
	if (CMouse::Rep(MOUSE_INPUT_RIGHT) && m_Player.GetIsCarry()) {
		m_Player.IsCarryOff();
		m_Block.SetRBlockState(m_Player.GetCarryNum(), WAIT);
	}

	// ゲーム終了処理
	if (CMouse::Rep(MOUSE_INPUT_MIDDLE)) {
		m_MemEnd = 1;
		m_State = ENDWAIT;
		CFade::RequestFadeOut();
	}

	Update();
}

void CSceneGame::Update() {
	
}

//終了前処理
void CSceneGame::EndWait() {
	if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
		m_State = END;
	}
}

//終了処理
void CSceneGame::Exit() {

	m_Block.Exit();


	m_State = INIT;
	m_EndingNum = m_MemEnd;
}




