#pragma once

class CFps{
private:
	float m_frameRate;	 //今のフレームレートを保存
	int m_nowTime;		 //現在時間（ミリ秒）
	int m_prevTime;		 //ひとつ前の時間
	int m_prevDrawTime;
	int m_count;		 //カウント用
public:
	//FPS表示関数
	void PrintFps();

	//次のフレームに進んでもいいか
	bool IsNextFrame();

	//更新処理
	void StepFps();

	//FPS初期化
	void InitFps();

};



