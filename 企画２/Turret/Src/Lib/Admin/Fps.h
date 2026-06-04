#pragma once

class CFps{
private:
	static float m_frameRate;	 //今のフレームレートを保存
	static int m_nowTime;		 //現在時間（ミリ秒）
	static int m_prevTime;		 //ひとつ前の時間
	static int m_prevDrawTime;
	static int m_count;		 //カウント用
public:
	//FPS表示関数
	static void PrintFps();

	//次のフレームに進んでもいいか
	static bool IsNextFrame();

	//更新処理
	static void StepFps();

	//FPS初期化
	static void InitFps();

};



