#pragma once
#include "../../../Lib/Model/Object.h"

// 壁のボーン番号
enum tagWallFrame
{
	WALL_1,		// 壁の一番左
	WALL_2,		// ↓
	WALL_3,		// ↓
	WALL_4,		// 壁の真ん中
	WALL_5,		// ↑
	WALL_6,		// ↑
	WALL_7,		// 壁の一番右

	WALL_NUM
};

class CWall : public CObject
{
public:
	// 任意の壁のボーンの位置を取得
	VECTOR GetFrameMat(int frameNum);
	
};
