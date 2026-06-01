#pragma once
#include <DxLib.h>

const int PAD_MAX_NUM = 16;		//パッド接続上限

//パッド接続時の識別番号
static const int PAD_NUMBER[PAD_MAX_NUM] = {
	DX_INPUT_PAD1,
	DX_INPUT_PAD2,
	DX_INPUT_PAD3,
	DX_INPUT_PAD4,
	DX_INPUT_PAD5,
	DX_INPUT_PAD6,
	DX_INPUT_PAD7,
	DX_INPUT_PAD8,
	DX_INPUT_PAD9,
	DX_INPUT_PAD10,
	DX_INPUT_PAD11,
	DX_INPUT_PAD12,
	DX_INPUT_PAD13,
	DX_INPUT_PAD14,
	DX_INPUT_PAD15,
	DX_INPUT_PAD16
};

//パッド入力ボタン
enum PAD_BUTTON {
	PAD_UP,				//上方向ボタン
	PAD_DOWN,			//下方向ボタン
	PAD_LEFT,			//左方向ボタン
	PAD_RIGHT,			//右方向ボタン
	PAD_START,			//スタートボタン
	PAD_BACK,			//バックボタン
	PAD_LEFT_THUMB,		//左スティック押し込み
	PAD_RIGHT_THUMB,	//右スティック押し込み
	PAD_LEFT_SHOULDER,	//LBボタン
	PAD_RIGHT_SHOULDER,	//RBボタン

	PAD_LEFT_TRIGGER,	//LTボタン
	PAD_RIGHT_TRIGGER,	//RTボタン
	
	PAD_A,				//Aボタン
	PAD_B,				//Bボタン
	PAD_X,				//Xボタン
	PAD_Y,				//Yボタン

	PAD_NUM				//ボタンの総数
};

//パッドクラス
class CPad {
private:
	static int m_attachedNum;					//現在接続されている数
	static XINPUT_STATE m_pad[PAD_MAX_NUM];		//パッド情報構造体
	static XINPUT_STATE m_prevPad[PAD_MAX_NUM];	//前フレームのパッド情報
public:
	CPad();		//コンストラクタ
	~CPad();	//デストラクタ

	static void Init();		//初期化
	static void Step();		//更新
	static void Exit();		//終了


	// @pad_num : 情報がほしいパッド番号(0～16)
	// @button  : 情報がほしいボタンの種類
	//通常入力情報（単押し情報）
	static bool Rep(int pad_num,PAD_BUTTON button);

	//トリガー入力情報
	static bool Trg(int pad_num, PAD_BUTTON button);

	//左スティックの入力情報取得
	static void LStick(int pad_num, int& x, int& y);
	//右スティックの入力情報取得
	static void RStick(int pad_num, int& x, int& y);

	//左スティックの回転方向取得
	static float LStickRot(int pad_num);
	//右スティックの回転方向取得
	static float RStickRot(int pad_num);

	//コントローラーが繋がっているか
	static bool IsConnect();

	static bool None(int pad_num);
};


