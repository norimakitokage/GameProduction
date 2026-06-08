#pragma once
#include "Sky/Sky.h"

class CLandformManager
{
private:
	CSky m_Sky;

public:
	void Init();
	void Load();
	void Exit();
	void Draw();

};