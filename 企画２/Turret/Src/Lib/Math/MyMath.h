#pragma once
#include <DxLib.h>
#include <math.h>

class CMath {
public:
	//==========================================
	// ベクトルの計算
	// =========================================
	//距離の計算
	static float GetDistance(float x1, float y1, float x2, float y2);

	//ベクトルの加算
	static VECTOR VecAdd(VECTOR vec1, VECTOR vec2);

	//ベクトルの減算
	static VECTOR VecCreate(VECTOR endPos, VECTOR startPos);

	//ベクトルの長さを取得
	static float GetVecLength(VECTOR vec);

	//ベクトルの正規化
	static VECTOR VecNorm(VECTOR vec, float length);

	//ベクトルのスカラー倍
	static VECTOR VecScale(VECTOR vec, float scale);

	//内積の計算
	static float VecDot(VECTOR vec1, VECTOR vec2);


	//==========================================
	// 行列の計算
	// =========================================
	//単位行列を取得する
	static MATRIX GetIdentityMatrix();

	//平行移動行列を取得する
	static MATRIX GetTranslateMatrix(float x, float y, float z);
	static MATRIX GetTranslateMatrix(VECTOR v);

	//拡縮行列を取得する
	static MATRIX GetScaleMatrix(float x, float y, float z);
	static MATRIX GetScaleMatrix(VECTOR v);

	//X軸回転行列を取得する
	static MATRIX GetPitchMatrix(float rot);

	//Y軸回転行列を取得する
	static MATRIX GetYawMatrix(float rot);

	//Z軸回転行列を取得する
	static MATRIX GetRollMatrix(float rot);

	//引数で渡された2つの行列を足し算する
	static MATRIX MatAdd(MATRIX mat1, MATRIX mat2);

	//引数で渡された2つの行列を引き算する
	static MATRIX MatSub(MATRIX mat1, MATRIX mat2);

	//引数で渡された行列をスカラー倍する
	static MATRIX MatScale(MATRIX mat, float scale);

	//引数で渡された2つの行列の掛け算を行う
	static MATRIX MatMult(MATRIX mat1, MATRIX mat2);

	//行列×ベクトルを行う(変換計算)
	static VECTOR MatTransform(MATRIX mat, VECTOR vec);

	//行列転置
	static MATRIX MatTranspose(MATRIX mat);

	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	//角度計算関係
	//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

	//角度をラジアンに変換
	static float TransRad(float degree);

	//ラジアンを角度に変換
	static float TransDegree(float rad);
};



