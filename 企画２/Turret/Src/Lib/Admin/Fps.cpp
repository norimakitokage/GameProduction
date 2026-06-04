#include <DxLib.h>
#include "Fps.h"

float CFps::m_frameRate;
int CFps::m_nowTime;
int CFps::m_prevTime;
int CFps::m_prevDrawTime;
int CFps::m_count;

// 最高フレームレート
constexpr int FRAME_RATE = 60;
// 1フレームのミリ秒
constexpr int FRAME_RATE_MILI_SECOND = 1000 / FRAME_RATE - 1;

void CFps::InitFps() {
	//基本的に0で初期化
	m_frameRate = 0.0f;
	m_count = 0;
	m_prevTime = m_prevDrawTime = GetNowCount();
	m_nowTime = 0;
}

bool CFps::IsNextFrame() {
	//最新の時間を取得し、更新する
	m_nowTime = GetNowCount();
	//前回の時間から今回までの差分を計算
	int difTime = m_nowTime - m_prevTime;

	//前回の時間から指定したフレーム分、時間が経過したかチェック
	if (difTime >= FRAME_RATE_MILI_SECOND)
	{
		return true;
	}
	else return false;
}

void CFps::StepFps()
{
	//ここまで来たら時間を更新
	m_prevTime = m_nowTime;
}

void CFps::PrintFps() {
	//１フレーム進んだはずと判断
	m_count++;
	//前回の時間と今回の時間の差を取得
	int difTime = m_nowTime - m_prevDrawTime;

	//差異が1秒以上あれば計算開始（1秒に1回フレームレートの表示を更新）
	if (difTime >= 1000)
	{
		//ある程度正常に動いていたら、m_countは60になっているはず
		float frameCount = (float)(m_count * 1000);
		//表示するfpsを更新
		m_frameRate = frameCount / difTime;
		//カウントは0に初期化
		m_count = 0;
		//ひとつ前の時間を更新
		m_prevDrawTime = m_nowTime;
	}

	//文字の表示　引数は「横の位置」「縦の位置」「色」「文字」
	//FPSは常に表示を続ける
	DrawFormatString(16, 16, GetColor(255, 0, 0), "FPS:%.2f", m_frameRate);
}






