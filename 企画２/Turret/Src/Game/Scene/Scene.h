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
	static CSceneBase* m_Scene;

public:
	// 初期化
	static void Init();
	// 更新
	static void Step();
	// 描画
	static void Draw();

public:
	// シーンの変更処理
	static void SetSceneType(tagSceneType type);

};
