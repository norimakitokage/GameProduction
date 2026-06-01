#pragma once

#include <DxLib.h>

class CColl
{
public:
	//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
	//		2Dの当たり判定
	//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーー


	// 点と四角の当たり判定
	//	dotPos		:	点の座標
	//	squarePos	:	四角形の中心座標
	//	width		:	四角形の横幅
	//	height		:	四角形の縦幅
	static bool DotToSquare(VECTOR dotPos, VECTOR squarePos,
		int width, int height);

	// 矩形同士の当たり判定
	//	squarePos	:	矩形の中心座標
	//	width		:	矩形の横幅
	//	height		:	矩形の縦幅
	static bool SquareToSquare(VECTOR squarePos1, int width1, int height1,
		VECTOR squarePos2, int width2, int height2);

	// 円同士の当たり判定
	//	circlePos	:	円の中心座標
	//	radius		:	円の半径
	static bool CircleToCircle(VECTOR circlePos1, int radius1,
		VECTOR circlePos2, int radius2);


	//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーー
	//		3Dの当たり判定
	//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

	//立方体同士の当たり判定
	//  pos		:　立方体の座標
	//　size		:　立方体の(横・縦・奥行)
	static bool BoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2);

	// 球同士の当たり判定
	//	circlePos	:	円の中心座標
	//	radius		:	円の半径
	static bool SphereToSphere(VECTOR circlePos1, float radius1,
		VECTOR circlePos2, float radius2);
};





