
#include "MyMath.h"
#include <DxLib.h>


//距離の計算
//x1からx2までの距離を計算
float CMath::GetDistance(float x1, float y1, float x2, float y2)
{
	float x = x2 - x1;
	float y = y2 - y1;

	return sqrtf(x * x + y * y);
}

//ベクトルの加算
//vec1にvec2の値を加算
VECTOR CMath::VecAdd(VECTOR vec1, VECTOR vec2){
	VECTOR res;
	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;

	return res;
}

//ベクトルの減算
//vec1からvec2の値を減算
VECTOR CMath::VecCreate(VECTOR endPos, VECTOR startPos){
	VECTOR res;
	res.x = endPos.x - startPos.x;
	res.y = endPos.y - startPos.y;
	res.z = endPos.z - startPos.z;

	return res;
}

//ベクトルの長さを取得
float CMath::GetVecLength(VECTOR vec)
{
	float res = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

	return sqrtf(res);
}

//ベクトルの正規化
VECTOR CMath::VecNorm(VECTOR vec, float length)
{
	VECTOR res;
	res.x = vec.x / length;
	res.y = vec.y / length;
	res.z = vec.z / length;

	return res;
}

//ベクトルのスカラー倍
VECTOR CMath::VecScale(VECTOR vec, float scale)
{
	VECTOR res;
	res.x = vec.x * scale;
	res.y = vec.y * scale;
	res.z = vec.z * scale;

	return res;
}

//内積の計算
float CMath::VecDot(VECTOR vec1, VECTOR vec2)
{
	float ret;

	ret = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z + vec2.z;

	return ret;
}

//単位行列を取得する
MATRIX CMath::GetIdentityMatrix() {
	MATRIX matrix = {0};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				matrix.m[i][j] = 1;
			}
			else {
				matrix.m[i][j] = 0;
			}
		}
	}
	return matrix;
}

//平行移動行列を取得する
MATRIX CMath::GetTranslateMatrix(float x, float y, float z) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][3] = x;
	matrix.m[1][3] = y;
	matrix.m[2][3] = z;

	return matrix;
}

MATRIX CMath::GetTranslateMatrix(VECTOR v) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][3] = v.x;
	matrix.m[1][3] = v.y;
	matrix.m[2][3] = v.z;
					 
	return matrix;
}

//拡縮行列を取得する
MATRIX CMath::GetScaleMatrix(float x, float y, float z) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = x;
	matrix.m[1][1] = y;
	matrix.m[2][2] = z;

	return matrix;
}

MATRIX CMath::GetScaleMatrix(VECTOR v) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = v.x;
	matrix.m[1][1] = v.y;
	matrix.m[2][2] = v.z;

	return matrix;
}

//X軸回転行列を取得する
MATRIX CMath::GetPitchMatrix(float rot) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[1][1] = cosf(rot);
	matrix.m[1][2] = -sinf(rot);
	matrix.m[2][1] = sinf(rot);
	matrix.m[2][2] = cosf(rot);

	return matrix;
}

//Y軸回転行列を取得する
MATRIX CMath::GetYawMatrix(float rot) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = cosf(rot);
	matrix.m[0][2] = sinf(rot);
	matrix.m[2][0] = -sinf(rot);
	matrix.m[2][2] = cosf(rot);

	return matrix;
}

//Z軸回転行列を取得する
MATRIX  CMath::GetRollMatrix(float rot) {
	MATRIX matrix = GetIdentityMatrix();
	matrix.m[0][0] = cosf(rot);
	matrix.m[0][1] = -sinf(rot);
	matrix.m[1][0] = sinf(rot);
	matrix.m[1][1] = cosf(rot);

	return matrix;
}

//引数で渡された2つの行列を足し算する
MATRIX CMath::MatAdd(MATRIX mat1, MATRIX mat2) {
	MATRIX matrix = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix.m[i][j] = mat1.m[i][j] + mat2.m[i][j];
		}
	}
	return matrix;
}

//行列の引き算(mat1からmat2を引く)
MATRIX CMath::MatSub(MATRIX mat1, MATRIX mat2) {
	MATRIX matrix = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix.m[i][j] = mat1.m[i][j] - mat2.m[i][j];
		}
	}
	return matrix;
}

//行列のスカラー倍
MATRIX CMath::MatScale(MATRIX mat, float scale) {
	MATRIX matrix = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix.m[i][j] = mat.m[i][j] * scale;
		}
	}
	return matrix;
}

//行列の掛け算
MATRIX CMath::MatMult(MATRIX mat1, MATRIX mat2) {
	MATRIX matrix = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < 4; l++) {
				matrix.m[i][j] += (mat1.m[i][l] * mat2.m[l][j]);
			}
		}
	}

	return matrix;
}

//行列×ベクトル
VECTOR CMath::MatTransform(MATRIX mat, VECTOR vec) {
	MATRIX matrix = { 0 };
	float fVec[4] = { vec.x, vec.y, vec.z, 1 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix.m[i][0] += mat.m[i][j] * fVec[j];
		}
	}
	VECTOR v = { matrix.m[0][0], matrix.m[1][0],matrix.m[2][0] };
	
	return v;
}

//行列転置
MATRIX CMath::MatTranspose(MATRIX mat) {
	MATRIX matrix = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix.m[j][i] = mat.m[i][j];
		}
	}

	return matrix;
}

//度をラジアンに変換
float CMath::TransRad(float degree) {
	return degree * DX_PI_F / 180.0f;
}

//ラジアンを度に変換
float CMath::TransDegree(float rad) {
	return rad * 180.0f / DX_PI_F;
}

