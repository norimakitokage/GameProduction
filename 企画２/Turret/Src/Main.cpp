#include <DxLib.h>			// DxLibを使用するために必須
#include "Common.h"
#include "Game/Scene/Scene.h"
#include "Lib/Admin/Fps.h"
#include "Lib/Controll/Keyboard/Key.h"
#include "Lib/controll/mouse/mouse.h"


// ゲームプログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);			// ウィンドウモードにするかどうか
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);		// ウィンドウの解像度を設定する
	SetMainWindowText("GAME");

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag( false );
#endif

	// ＤＸライブラリ初期化処理　基本的にはこれより後でDxLib関数を使う
	if (DxLib_Init() == -1) return -1;

	// 一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);	// 画面のちらつきを無くす
	SetTransColor(255, 0, 255);		// 透過色指定　今回は真紫色を透明
	SetUseASyncLoadFlag(false);
	
	//当たり判定の球をきれいに表示
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//ライティング計算の設定
	SetUseLighting(true);
	//マウスを不可視化
	SetMouseDispFlag(false);

	// FPS管理クラス
	CFps::InitFps();

	//シーン管理クラス
	CScene::Init();

	//ゲームメインループ
	while (ProcessMessage() != -1)	// 問題が発生したら終了
	{
		Sleep(1);
		// 「escキー」が押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		if (!CFps::IsNextFrame()) continue;

		// 画面を一度何もない状態へ
		ClearDrawScreen();

		CFps::StepFps();

		// ゲーム本体の命令はこれより下に書く

		//入力情報取得＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
		CMouse::Update();
		CKey::Step();
		//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

		//シーン管理＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
		CScene::Step();
		CScene::Draw();
		//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

		//デバッグ用
#ifdef DEBUG
		//g_Fps.PrintFps();
#endif // DEBUG

		// ゲーム本体の命令はこれより上に書く

		// 作成した画面をモニターへ転送
		ScreenFlip();
	}

	// 終了前処理==================
	

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	//=============================

	return 0;				// プログラムの終了 
}
