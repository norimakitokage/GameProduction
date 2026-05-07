#include "Player.h"
#include "../../Lib/Controll/Mouse/Mouse.h"

void CPlayer::Init() 
{
	CMouse::GetPos(m_X, m_Y);
	m_IsCarry = false;
}

void CPlayer::Load()
{
}

void CPlayer::Step()
{
	CMouse::GetPos(m_X, m_Y);
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

void CPlayer::IsCarryOn()
{
	m_IsCarry = true;
}

void CPlayer::IsCarryOff()
{
	m_IsCarry = false;
}

bool CPlayer::GetIsCarry()
{
	return m_IsCarry;
}

void CPlayer::SetCarryNum(int i)
{
	m_CarryNum = i;
}

int CPlayer::GetCarryNum()
{
	return m_CarryNum;
}
