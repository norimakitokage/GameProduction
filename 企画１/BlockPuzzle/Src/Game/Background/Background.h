#pragma once
#include <Dxlib.h>



class CBackground
{
private:
	int m_BackgroundHndl;		// ”wŒi‚Ì‰æ‘œ

	

public:
	void Init();
	void Load();
	void Step();
	void Exit();
	void Draw();
};
