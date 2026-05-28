#include "UI.h"
#include "../../../Lib/Admin/Data.h"
#include <DxLib.h>
#include "../../../Common.h"

int CUI::m_Hndl[tagScoreUp::num];
bool CUI::m_RateFlag;
int CUI::m_Shade;
int CUI::m_Mem;

const int SCORE_X = (WINDOW_SIZE_X / 3) * 2;

const int SCORE_Y = 60;

const int DEFOLT_SHADE = 255;

const char* HNDL_PATH[] = {
	"Data/Graph/bai2.png",
	"Data/Graph/bai3.png",
	"Data/Graph/bai4.png",
	"Data/Graph/bai5.png",
	"Data/Graph/bai6.png",
};

void CUI::Init()
{
	for (int i = 0; i < tagScoreUp::num; i++) {
		m_Hndl[i] = -1;
	}
	m_RateFlag = false;
	m_Shade = DEFOLT_SHADE;
}

void CUI::Load()
{
	for (int i = 0; i < tagScoreUp::num; i++) {
		m_Hndl[i] = LoadGraph(HNDL_PATH[i]);
	}
}

void CUI::DrawScore()
{
	CData* data = CData::GetInstance();

	int score = data->GetScore();

	SetFontSize(30);
	DrawFormatString(SCORE_X, SCORE_Y, WHITE, "SCOREÅF%d", score);
	SetFontSize(16);
}

void CUI::DrawRate()
{
	if (m_RateFlag) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_Shade);
		// ê}å`ÇÃï`âÊ
		DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 2.0f, 0.0f, m_Hndl[m_Mem - 2], TRUE);
		// ê}å`ÇîñÇ≠ÇµÇƒÇ¢Ç≠
		m_Shade -= 5;
		if (m_Shade <= 0) {
			m_RateFlag = false;
			m_Shade = DEFOLT_SHADE;
		}

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	}
}

void CUI::Request(int num)
{
	m_RateFlag = true;
	m_Mem = num;
}
