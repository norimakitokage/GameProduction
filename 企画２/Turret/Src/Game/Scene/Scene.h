#pragma once
#include "SceneBase.h"
#include "../../Lib/Singleton/Singleton.h"

class CSceneTitle;
class CSceneGame;
class CSceneDefeat;
class CSceneClear;

enum tagSceneType{
	TITLE,
	GAME,
	DEFEAT,
	CLEAR,

	NUM
};

class CScene : public CSingleton
{
private:
	// 現在のシーン
	//tagSceneType m_State;
	// 現在動かしているシーン
	CSceneBase* m_Scene;

public:
	// 初期化
	void Init();
	// 更新
	void Step();
	// 描画
	void Draw();

public:
	// シーンの変更処理
	void SetSceneType(tagSceneType type);

};
