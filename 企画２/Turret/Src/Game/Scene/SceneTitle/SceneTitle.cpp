#include <DxLib.h>
#include "../../../Common.h"
#include "SceneTitle.h"
#include "../Scene.h"
#include "../../../Lib/Fade/Fade.h"
#include "../../../Lib/Controll/Keyboard/Key.h"

void CSceneTitle::Draw()
{
	switch (m_State)
	{
	case CSceneBase::STARTWAIT:
	case CSceneBase::STEP:
	case CSceneBase::UPDATE:
	case CSceneBase::ENDWAIT:
		DrawFormatString(WINDOW_SENTER_X, WINDOW_SENTER_Y, WHITE, "ƒ^ƒCƒgƒ‹");

		break;
	}
}


void CSceneTitle::Init()
{
	m_State = LOAD;
}

void CSceneTitle::Load()
{

	CFade::RequestFadeIn();
	m_State = STARTWAIT;
}

void CSceneTitle::StartWait()
{
	if (CFade::IsEndFadeIn()) {
		m_State = STEP;
	}
}

void CSceneTitle::Step()
{
	if (CKey::Rep(KEY_INPUT_RETURN)) {
		CFade::RequestFadeOut();
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneTitle::Update()
{
	m_State = STEP;
}

void CSceneTitle::EndWait()
{
	if (CFade::IsEndFadeOut()) {
		m_State = EXIT;
	}
}

void CSceneTitle::Exit()
{
	CScene::SetSceneType(tagSceneType::GAME);

	m_State = INIT;
}
