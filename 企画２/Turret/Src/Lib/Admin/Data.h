#pragma once
#include "../Singleton/Singleton.h"

class CData : public CSingleton{
private:
	int m_Score;			//ゲームのスコア

public:
	//インスタンス取得
	/*static CData* GetInstance();
	
	static void DeleteInstance();*/

	//スコア操作
	int GetScore() { return m_Score; }
	void SetScore(int num) { m_Score = num; }
	void AddScore(int num) { m_Score += num; }

private:
	//static CData* m_instance;

	CData() { m_Score = 0; }
	~CData() {}
};


