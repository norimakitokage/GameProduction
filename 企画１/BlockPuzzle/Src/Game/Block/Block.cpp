#include "Block.h"
#include "../../Common.h"

void CBlock::Init(int X, int Y)
{
	m_Center = VGet((float)X, (float)Y, 0.0f);
	m_Flag = false;
}

void CBlock::Step()
{
	if (m_AnimFlag) {

	}
}

void CBlock::Update() {
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

void CBlock::SetFlagOn()
{
	m_Flag = true;
}
