#pragma once
#include "SceneTitle/SceneTitle.h"
#include "SceneResualt/SceneResualt.h"
#include "SceneGame/SceneGame.h"

//シーンのタグ
enum tagScene {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESUALT,

	SCENE_NUM
};

//シーン管理クラス
class CScene {
private:
	tagScene m_state;		//現在のシーン

	CSceneTitle m_title;		//タイトルクラス
	CSceneResualt m_resualt;	//リザルトクラス
	CSceneGame m_game;			//ゲーム本編クラス
public:
	CScene();
	~CScene();

	void Init();		//初期化
	void Step();		//更新
	void Draw();		//描画
	void Exit();
};


