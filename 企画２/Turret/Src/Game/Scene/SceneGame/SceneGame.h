#pragma once
#include "../SceneBase.h"
#include "../../Player/Player.h"
#include "../../Camera/CameraManager.h"



class CSceneGame : public CSceneBase
{
private:
	CPlayer m_Player;

	CCameraManager m_Camera;

public:

	void Draw();

private:
	void Init();
	void Load();
	void StartWait();
	void Step();
	void Update();
	void EndWait();
	void Exit();
};
