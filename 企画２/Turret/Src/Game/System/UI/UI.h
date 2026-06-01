#pragma once

enum tagScoreUp
{
	tow,
	three,
	four,
	five,
	six,

	num
};

class CUI
{
private:
	static int m_Hndl[tagScoreUp::num];
	// 表示するかどうかのフラグ
	static bool m_RateFlag;
	// 濃淡
	static int m_Shade;
	// 表示する番号
	static int m_Mem;
public:
	static void Init();
	static void Load();

public:
	// スコアの表示
	static void DrawScore();

	// 何倍になったか表示
	static void DrawRate();

	static void Request(int num);
};

