#include "Scene.h"
#include "SceneTitle/SceneTitle.h"
#include "SceneGame/SceneGame.h"
#include "SceneDefeat/SceneDefeat.h"
#include "SceneClear/SceneClear.h"
#include "../../Lib/Fade/Fade.h"

CSceneBase* CScene::m_Scene = nullptr;

void CScene::Init()
{
	CFade::Init();
	m_Scene = new CSceneTitle();
}

void CScene::Step()
{
	m_Scene->Loop();

	CFade::Step();
}

void CScene::Draw()
{
	m_Scene->Draw();

	CFade::Draw();
}

void CScene::SetSceneType(tagSceneType type)
{
	delete m_Scene;

	switch (type)
	{
	case TITLE:
		m_Scene = new CSceneTitle();
		break;
	case GAME:
		m_Scene = new CSceneGame();
		break;
	case DEFEAT:
		m_Scene = new CSceneDefeat();
		break;
	case CLEAR:
		m_Scene = new CSceneClear();
		break;
	}
}
