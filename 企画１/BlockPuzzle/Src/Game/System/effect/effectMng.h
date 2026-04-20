#pragma once
#include "../../../lib//effekseer/effekseer.h"

enum tagEffect {
	KILL_ENEMY,

	ALL_EFFECT
};

//エフェクト管理クラス
class CEffectMng {
private:
	tagEffect m_id;
public:
	static void Init();		//初期化
	static void Load();		//読み込み
	static void Step();		//更新
	static void Draw();		//描画
	static void Exit();		//終了処理

	//エフェクトの呼び出し
	static void Request(int ID, VECTOR Pos, bool Loop);
};
