#pragma once


class CSceneBase
{
protected:
	enum tagSceneState
	{
		INIT,
		LOAD,
		STARTWAIT,
		STEP,
		UPDATE,
		ENDWAIT,
		EXIT,

		NUM
	};

	tagSceneState m_State;

public:
	CSceneBase();
	virtual ~CSceneBase();

	// シーンを動かす
	virtual void Loop();
	// シーンの描画
	virtual void Draw() = 0;

private:
	virtual void Init() = 0;
	virtual void Load() = 0;
	virtual void StartWait() = 0;
	virtual void Step() = 0;
	virtual void Update() = 0;
	virtual void EndWait() = 0;
	virtual void Exit() = 0;
};
