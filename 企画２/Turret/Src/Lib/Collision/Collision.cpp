#include "collision.h"

//点と矩形
bool CColl::DotToSquare(VECTOR dotPos, VECTOR squarePos,
	int width, int height) {

	// 四角形の上下左右それぞれの座標を計算する
	float up = squarePos.y - height * 0.5f;
	float down = squarePos.y + height * 0.5f;
	float left = squarePos.x - width * 0.5f;
	float right = squarePos.x + width * 0.5f;

	// 4つの端をそれぞれチェックして、すべての条件を満たしたらヒット！
	if (dotPos.x >= left && dotPos.x <= right
		&& dotPos.y >= up && dotPos.y <= down)
	{
		return true;
	}
	else return false;
}

//矩形同士
bool CColl::SquareToSquare(VECTOR squarePos1, int width1, int height1,
	VECTOR squarePos2, int width2, int height2) {

	// 四角形の上下左右それぞれの座標を計算する
	float up1 = squarePos1.y - height1 * 0.5f;
	float down1 = squarePos1.y + height1 * 0.5f;
	float left1 = squarePos1.x - width1 * 0.5f;
	float right1 = squarePos1.x + width1 * 0.5f;

	float up2 = squarePos2.y - height2 * 0.5f;
	float down2 = squarePos2.y + height2 * 0.5f;
	float left2 = squarePos2.x - width2 * 0.5f;
	float right2 = squarePos2.x + width2 * 0.5f;

	// 4つの端をそれぞれチェックして、すべての条件を満たしたらヒット！
	if (left1 <= right2 && right1 >= left2
		&& up1 <= down2 && down1 >= up2)
	{
		return true;
	}
	else return false;
}

//円同士
bool CColl::CircleToCircle(VECTOR circlePos1, int radius1,
	VECTOR circlePos2, int radius2) {

	// 円1から円2までの距離を計算
	float lengthX = circlePos1.x - circlePos2.x;	// どうせ2乗するとマイナスが消えるので、順番はどうでもいい
	lengthX *= lengthX;
	float lengthY = circlePos1.y - circlePos2.y;	// どうせ2乗するとマイナスが消えるので、順番はどうでもいい
	lengthY *= lengthY;
	float length = lengthX + lengthY;	// これがaの2乗＋bの2乗

	// 2つの円の半径を加算し、2乗する
	float lengthRadius = (float)(radius1 + radius2);
	lengthRadius *= lengthRadius;

	// 以下の条件を満たせばヒットする！
	if (lengthRadius >= length)
	{
		return true;
	}
	else return false;
}

//立方体同士
bool CColl::BoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2) {

	// 四角形の上下左右奥行それぞれの座標を計算する
	float up1 = pos1.y - size1.y * 0.5f;
	float down1 = pos1.y + size1.y * 0.5f;
	float left1 = pos1.x - size1.x * 0.5f;
	float right1 = pos1.x + size1.x * 0.5f;
	float front1 = pos1.z - size1.x * 0.5f;
	float back1 = pos1.z + size1.x * 0.5f;

	float up2 = pos2.y - size2.y * 0.5f;
	float down2 = pos2.y + size2.y * 0.5f;
	float left2 = pos2.x - size2.x * 0.5f;
	float right2 = pos2.x + size2.x * 0.5f;
	float front2 = pos2.z - size2.x * 0.5f;
	float back2 = pos2.z + size2.x * 0.5f;

	// 端をそれぞれチェックして、すべての条件を満たしたらヒット！
	if (left1 <= right2 && right1 >= left2
		&& up1 <= down2 && down1 >= up2
		&& front1 <= back2 && back1 >= front2)
	{
		return true;
	}
	else return false;
}

//球同士
bool CColl::SphereToSphere(VECTOR circlePos1, float radius1,
	VECTOR circlePos2, float radius2) {

	// 円1から円2までの距離を計算
	float lengthX = circlePos1.x - circlePos2.x;	// どうせ2乗するとマイナスが消えるので、順番はどうでもいい
	lengthX *= lengthX;

	float lengthY = circlePos1.y - circlePos2.y;	// どうせ2乗するとマイナスが消えるので、順番はどうでもいい
	lengthY *= lengthY;

	float lengthZ = circlePos1.z - circlePos2.z;
	lengthZ *= lengthZ;

	float length = lengthX + lengthY + lengthZ;	// これがaの2乗＋bの2乗

	// 2つの円の半径を加算し、2乗する
	float lengthRadius = (float)(radius1 + radius2);
	lengthRadius *= lengthRadius;

	// 以下の条件を満たせばヒットする！
	if (lengthRadius >= length)
	{
		return true;
	}
	else return false;
}


