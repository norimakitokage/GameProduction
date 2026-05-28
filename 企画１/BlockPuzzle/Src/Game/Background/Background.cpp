#include "Background.h"
#include "../../Common.h"

void CBackground::Init()
{
	m_BackgroundHndl = -1;
}

void CBackground::Load()
{
	if (m_BackgroundHndl == -1) {
		m_BackgroundHndl = LoadGraph("Data/Graph/iseki.png");
	}
}

void CBackground::Exit()
{
	if (m_BackgroundHndl != -1) {
		DeleteGraph(m_BackgroundHndl);
		m_BackgroundHndl = -1;
	}
}

void CBackground::Draw()
{
	DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 1.0f, 0.0f, m_BackgroundHndl, TRUE);
}
