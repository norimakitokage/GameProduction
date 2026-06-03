#include "SceneGame.h"
#include <DxLib.h>
#include "../../../Common.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Fade/Fade.h"
#include "../Scene.h"

void CSceneGame::Draw()
{
	switch (m_State)
	{
	case CSceneBase::STARTWAIT:
	case CSceneBase::STEP:
	case CSceneBase::UPDATE:
	case CSceneBase::ENDWAIT:
		DrawFormatString(WINDOW_SENTER_X, WINDOW_SENTER_Y, WHITE, "ÉQÅ[ÉÄ");

		break;
	}
}


void CSceneGame::Init()
{
	m_State = LOAD;
}

void CSceneGame::Load()
{
	CFade::RequestFadeOut();
	m_State = STARTWAIT;
}

void CSceneGame::StartWait()
{
	if (CFade::IsEndFadeOut) {
		m_State = STEP;
	}
}

void CSceneGame::Step()
{
	if (CKey::Rep(KEY_INPUT_RETURN)) {
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneGame::Update()
{
	m_State = STEP;
}

void CSceneGame::EndWait()
{
	m_State = EXIT;
}

void CSceneGame::Exit()
{
	CScene::SetSceneType(tagSceneType::TITLE);

	m_State = INIT;
}
