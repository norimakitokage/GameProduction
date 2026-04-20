#pragma once
#include <DxLib.h>

const int BUFF_MAX = 256;	//配列bufの最大値

//キーボードクラス
class CKey
{
private:
	static char buf[BUFF_MAX];		//キー情報保存
	static char prevBuf[BUFF_MAX];	//前フレームキー情報
public:
	static void Init();			//初期化
	static void Step();			//更新

	static bool Rep(int key);	//単押し
	static bool Trg(int key);	//長押し

	//押されていないか確認
	// @return   true:何も押されていない
	//		　  false:何かしら押されている
	static bool None();			
};

