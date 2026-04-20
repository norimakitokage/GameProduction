#include "Scene.h"
#include "../../Lib/Fade/Fade.h"

CScene::CScene() {
	m_state = SCENE_TITLE;
}

CScene::~CScene() {
	m_state = SCENE_TITLE;
}

//èâä˙âª
void CScene::Init() {
	m_state = SCENE_TITLE;
	CFade::Init();
}

//çXêV
void CScene::Step() {
	switch (m_state)
	{
	case SCENE_TITLE:
		if (m_title.Loop() != -1) {
			m_state = SCENE_GAME;
		}
		break;
	case SCENE_GAME:
		if (m_game.Loop() != -1) {
			m_state = SCENE_RESUALT;
		}
		break;
	case SCENE_RESUALT:
		if (m_resualt.Loop() != -1) {
			m_state = SCENE_TITLE;
		}
		break;
	}
	CFade::Step();
}

//ï`âÊ
void CScene::Draw() {
	switch (m_state)
	{
	case SCENE_TITLE:
		m_title.Draw();
		break;
	case SCENE_GAME:
		m_game.Draw();
		break;
	case SCENE_RESUALT:
		m_resualt.Draw();
		break;
	}
	CFade::Draw();
}

void CScene::Exit() {

}



