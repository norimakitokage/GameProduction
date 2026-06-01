#pragma once
#include "../SceneBase.h"

class CSceneGame : public CSceneBase
{
private:

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
