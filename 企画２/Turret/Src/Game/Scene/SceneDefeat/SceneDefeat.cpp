#include "SceneDefeat.h"
#include <DxLib.h>
#include "../../../Common.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Fade/Fade.h"
#include "../Scene.h"

void CSceneDefeat::Draw()
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


void CSceneDefeat::Init()
{
	m_State = LOAD;
}

void CSceneDefeat::Load()
{
	CFade::RequestFadeOut();
	m_State = STARTWAIT;
}

void CSceneDefeat::StartWait()
{
	if (CFade::IsEndFadeOut) {
		m_State = STEP;
	}
}

void CSceneDefeat::Step()
{
	if (CKey::Rep(KEY_INPUT_RETURN)) {
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneDefeat::Update()
{
	m_State = STEP;
}

void CSceneDefeat::EndWait()
{
	m_State = EXIT;
}

void CSceneDefeat::Exit()
{
	CScene::SetSceneType(tagSceneType::TITLE);

	m_State = INIT;
}
