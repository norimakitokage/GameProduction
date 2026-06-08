#include "LandformManager.h"

const VECTOR SKY_SIZE = VGet(60.0f, 60.0f, 60.0f);

void CLandformManager::Init()
{
	m_Sky.Init();
}

void CLandformManager::Load()
{
	m_Sky.LoadModel("Data/Landform/Sky/sky.mv1");
	m_Sky.SetScale(SKY_SIZE);
	m_Sky.Update();
}

void CLandformManager::Exit()
{
	m_Sky.Exit();
}

void CLandformManager::Draw()
{
	m_Sky.Draw();
}
