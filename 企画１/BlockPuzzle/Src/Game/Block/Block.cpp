#include "Block.h"
#include "../../Common.h"

void CBlock::Init(int X, int Y)
{
	m_Center = VGet((float)X, (float)Y, 0.0f);
	m_Flag = false;

	m_AnimFlag = false;
	m_Count = 0;

	m_IsTouch = false;
}

void CBlock::Step()
{
	if (m_AnimFlag) {
		m_Count++;
	}
}

void CBlock::Calc() {
	m_Flag = false;
	m_AnimFlag = true;
}

VECTOR CBlock::GetPosition()
{
	return m_Center;
}

bool CBlock::GetFlag()
{
	return m_Flag;
}

void CBlock::FlagOn()
{
	m_Flag = true;
}

void CBlock::FlagOFF()
{
	m_Flag = false;
}
