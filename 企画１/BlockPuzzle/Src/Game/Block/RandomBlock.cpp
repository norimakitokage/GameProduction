#include "RandomBlock.h"
#include "BlockManager.h"
#include "../../Lib/Math/Getrand.h"

void CRandBlock::Init()
{
	m_State = WAIT;

	m_Type = Random();
}

void CRandBlock::Step(int x, int y)
{
	switch (m_State)
	{
	case WAIT:
		break;
	case CARRY:
		m_X = x;
		m_Y = y;
		break;
	case DONE:
		break;
	}
}

void CRandBlock::Exit()
{
	//m_State = WAIT;
}

void CRandBlock::Draw(int hndl)
{

	if (m_State == CARRY) {

		int left, right, up, down;
		left = m_X - BLOCK_HALF;
		right = m_X + BLOCK_HALF;
		up = m_Y - BLOCK_HALF;
		down = m_Y + BLOCK_HALF;

		switch (m_Type)
		{
		case TYPE_1:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			break;
		case TYPE_2:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			break;
		case TYPE_3:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			break;
		case TYPE_4:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			break;
		case TYPE_5:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_6:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 右 + 1
			DrawModiGraph(right + BLOCK_SIZE, up, right + BLOCK_SIZE + BLOCK_SIZE, up,
				right + BLOCK_SIZE + BLOCK_SIZE, down, right + BLOCK_SIZE, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			break;
		case TYPE_7:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			// 下 + 1
			DrawModiGraph(left, down + BLOCK_SIZE, right, down + BLOCK_SIZE,
				right, down + BLOCK_SIZE + BLOCK_SIZE, left, down + BLOCK_SIZE + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_8:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 右 + 1
			DrawModiGraph(right + BLOCK_SIZE, up, right + BLOCK_SIZE + BLOCK_SIZE, up,
				right + BLOCK_SIZE + BLOCK_SIZE, down, right + BLOCK_SIZE, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 左 + 1
			DrawModiGraph(left - BLOCK_SIZE - BLOCK_SIZE, up, left - BLOCK_SIZE, up,
				left - BLOCK_SIZE, down, left - BLOCK_SIZE - BLOCK_SIZE, down, hndl, TRUE);
			break;
		case TYPE_9:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 上 + 1
			DrawModiGraph(left, up - BLOCK_SIZE - BLOCK_SIZE, right, up - BLOCK_SIZE - BLOCK_SIZE,
				right, up - BLOCK_SIZE, left, up - BLOCK_SIZE, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			// 下 + 1
			DrawModiGraph(left, down + BLOCK_SIZE, right, down + BLOCK_SIZE,
				right, down + BLOCK_SIZE + BLOCK_SIZE, left, down + BLOCK_SIZE + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_10:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			break;
		case TYPE_11:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			break;
		case TYPE_12:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_13:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_14:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 左 + 1
			DrawModiGraph(left - BLOCK_SIZE - BLOCK_SIZE, up, left - BLOCK_SIZE, up,
				left - BLOCK_SIZE, down, left - BLOCK_SIZE - BLOCK_SIZE, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 上 + 1
			DrawModiGraph(left, up - BLOCK_SIZE - BLOCK_SIZE, right, up - BLOCK_SIZE - BLOCK_SIZE,
				right, up - BLOCK_SIZE, left, up - BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_15:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 右 + 1
			DrawModiGraph(right + BLOCK_SIZE, up, right + BLOCK_SIZE + BLOCK_SIZE, up,
				right + BLOCK_SIZE + BLOCK_SIZE, down, right + BLOCK_SIZE, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 上 + 1
			DrawModiGraph(left, up - BLOCK_SIZE - BLOCK_SIZE, right, up - BLOCK_SIZE - BLOCK_SIZE,
				right, up - BLOCK_SIZE, left, up - BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_16:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 右 + 1
			DrawModiGraph(right + BLOCK_SIZE, up, right + BLOCK_SIZE + BLOCK_SIZE, up,
				right + BLOCK_SIZE + BLOCK_SIZE, down, right + BLOCK_SIZE, down, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			// 下 + 1
			DrawModiGraph(left, down + BLOCK_SIZE, right, down + BLOCK_SIZE,
				right, down + BLOCK_SIZE + BLOCK_SIZE, left, down + BLOCK_SIZE + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_17:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 左 + 1
			DrawModiGraph(left - BLOCK_SIZE - BLOCK_SIZE, up, left - BLOCK_SIZE, up,
				left - BLOCK_SIZE, down, left - BLOCK_SIZE - BLOCK_SIZE, down, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			// 下 + 1
			DrawModiGraph(left, down + BLOCK_SIZE, right, down + BLOCK_SIZE,
				right, down + BLOCK_SIZE + BLOCK_SIZE, left, down + BLOCK_SIZE + BLOCK_SIZE, hndl, TRUE);
			break;
		case TYPE_18:
			DrawModiGraph(left, up, right, up, right, down, left, down, hndl, TRUE);
			// 右
			DrawModiGraph(right, up, right + BLOCK_SIZE, up,
				right + BLOCK_SIZE, down, right, down, hndl, TRUE);
			// 左
			DrawModiGraph(left - BLOCK_SIZE, up, left, up,
				left, down, left - BLOCK_SIZE, down, hndl, TRUE);
			// 上
			DrawModiGraph(left, up - BLOCK_SIZE, right, up - BLOCK_SIZE,
				right, up, left, up, hndl, TRUE);
			// 下
			DrawModiGraph(left, down, right, down,
				right, down + BLOCK_SIZE, left, down + BLOCK_SIZE, hndl, TRUE);
			// 右上
			DrawModiGraph(right, up - BLOCK_SIZE, right + BLOCK_SIZE, up - BLOCK_SIZE,
				right + BLOCK_SIZE, up, right, up, hndl, TRUE);
			// 右下
			DrawModiGraph(right, down, right + BLOCK_SIZE, down,
				right + BLOCK_SIZE, down + BLOCK_SIZE, right, down + BLOCK_SIZE, hndl, TRUE);
			// 左下
			DrawModiGraph(left - BLOCK_SIZE, down, left, down,
				left, down + BLOCK_SIZE, left - BLOCK_SIZE, down + BLOCK_SIZE, hndl, TRUE);
			// 左上
			DrawModiGraph(left - BLOCK_SIZE, up - BLOCK_SIZE, left, up - BLOCK_SIZE,
				left, up, left - BLOCK_SIZE, up, hndl, TRUE);
			break;
		}
	}
}

void CRandBlock::Calc()
{
	m_IsPut = false;
	m_Type = Random();
	m_State = WAIT;
}

void CRandBlock::SetState(tagRandState state)
{
	m_State = state;
}

tagRandState CRandBlock::GetState()
{
	return m_State;
}

tagRandBlockType CRandBlock::GetType()
{
	return m_Type;
}

tagRandBlockType CRandBlock::Random()
{
	// ブロックを抽選
	int i = -1;
	i = CRand::Rand(0, (int)(tagRandBlockType::NUMBER - 1));

	return (tagRandBlockType)i;
}
