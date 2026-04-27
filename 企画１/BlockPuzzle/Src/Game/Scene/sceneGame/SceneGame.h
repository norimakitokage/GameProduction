#pragma once
#include <DxLib.h>
#include "../../Block/BlockManager.h"

//複数のカメラを管理する
class CSceneGame {
private:
	//ゲームの処理の流れ
	enum tagScene {
		INIT,			//初期化
		LOAD,			//読み込み
		STARTWAIT,
		MAIN,			//更新
		ENDWAIT,
		END,			//データの破棄

		NUM
	};
	tagScene m_State;			//シーンの状態
	int m_EndingNum;			//Loopのリターンで返す変数A
	int m_MemEnd;				//次のシーンの分岐を記憶

private:
	CBlockManager m_Block;
	
public:
	CSceneGame();
	~CSceneGame();

	//更新
	int Loop();
	//描画
	void Draw();

private:
	//初期化
	void Init();
	//読み込み
	void Load();
	//スタート待機
	void StartWait();
	
	// 更新
	void Step();

	//上書き
	void Update();
	//終了待機
	void EndWait();
	//データの消去
	void Exit();
};

