#include "SceneClear.h"
#include <DxLib.h>
#include "../../../Common.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Fade/Fade.h"
#include "../Scene.h"

void CSceneClear::Draw()
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


void CSceneClear::Init()
{
	m_State = LOAD;
}

void CSceneClear::Load()
{
	CFade::RequestFadeOut();
	m_State = STARTWAIT;
}

void CSceneClear::StartWait()
{
	if (CFade::IsEndFadeOut) {
		m_State = STEP;
	}
}

void CSceneClear::Step()
{
	if (CKey::Rep(KEY_INPUT_RETURN)) {
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneClear::Update()
{
	m_State = STEP;
}

void CSceneClear::EndWait()
{
	m_State = EXIT;
}

void CSceneClear::Exit()
{
	CScene::SetSceneType(tagSceneType::TITLE);

	m_State = INIT;
}
