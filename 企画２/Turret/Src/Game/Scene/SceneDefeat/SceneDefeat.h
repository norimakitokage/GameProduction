#pragma once
#include "../SceneBase.h"

class CSceneDefeat : public CSceneBase
{
private:

public:

	void Draw();

private:
	void Init() override;
	void Load() override;
	void StartWait() override;
	void Step() override;
	void Update() override;
	void EndWait() override;
	void Exit() override;
};
