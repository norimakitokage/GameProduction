#pragma once
#include "../../Lib/Model/Actor.h"

class CPlayer : public CActor
{
private:

public:
	void Init() override;
	void Load();
	void Step();
	void Update() override;
	void Exit() override;
	void Draw() override;
};


