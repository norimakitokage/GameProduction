#include "Wall.h"

VECTOR CWall::GetFrameMat(int frameNum)
{
	return MV1GetFramePosition(m_Hndl,frameNum);
}
