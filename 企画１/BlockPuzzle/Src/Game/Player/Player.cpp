#include "Player.h"
#include "../../Lib/Controll/Mouse/Mouse.h"

void CPlayer::Init() 
{
	CMouse::GetPos(m_X, m_Y);
}

void CPlayer::Load()
{
}

void CPlayer::Step()
{
	CMouse::GetPos(m_X, m_Y);

	switch (m_state)
	{
	case PLAYER_CHOOSE:

		break;
	case PLAYER_Drag:
		break;
	}
}

void CPlayer::Exit()
{

}

void CPlayer::Draw()
{

}


int CPlayer::GetX()
{
	return m_X;
}

int CPlayer::GetY()
{
	return m_Y;
}
