#include <DxLib.h>
#include "fade.h"
#include "../../common.h"

//定義関連
#define FADE_SPEED		(5)	//切り替わるスピード
#define FADE_SIZE_X		(WINDOW_SIZE_X)	//フェード画面の横幅
#define FADE_SIZE_Y		(WINDOW_SIZE_Y)	//フェード画面の縦幅

tagFadeState CFade::m_id;
int CFade::m_count;

//フェードの初期化
void CFade::Init()
{
	m_id = FADE_NON;
	m_count = 0;
}


//フェードのロード（画像を差し込むとき）
void CFade::Load()
{

}


//フェードの更新処理
void CFade::Step()
{
	switch (m_id)
	{
	case FADE_IN:
		//徐々に明るくするので、数値は減らす
		m_count -= FADE_SPEED;
		//0まで来たらフェードイン終了
		if (m_count <= 0)
		{
			m_count = 0;
			m_id = FADE_NON;
		}
		break;
	case FADE_OUT:
		//徐々に暗くするので、数値は増やす
		m_count += FADE_SPEED;
		//255まで来たらフェードアウト終了
		if (m_count >= 255)
		{
			m_count = 255;
			m_id = FADE_OUT_WAIT;
		}
		break;
	}
}


//フェードの画像描画
void CFade::Draw()
{
	//黒画像を描画	
	switch (m_id)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		//まずはここでアルファ値をセット
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_count);

		//フェード用の黒い四角を表示
		DrawBox(0, 0, FADE_SIZE_X, FADE_SIZE_Y,
			GetColor(0, 0, 0), TRUE);

		//ほかの画像に影響を出さないよう、初期設定に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}


//フェードの削除（画像を差し込むとき）
void CFade::Exit()
{

}


//フェードインリクエスト
void CFade::RequestFadeIn()
{
	m_count = 255;
	m_id = FADE_IN;
}


//フェードアウトリクエスト
void CFade::RequestFadeOut()
{
	m_count = 0;
	m_id = FADE_OUT;
}


//フェードインが終了したか
bool CFade::IsEndFadeIn()
{
	if (m_id == FADE_IN)
	{
		return false;
	}
	//他はすべて少なくともフェードインではない
	else return true;
}


//フェードアウトが終了したか
bool CFade::IsEndFadeOut()
{
	if (m_id == FADE_OUT)
	{
		return false;
	}
	//他はすべて少なくともフェードアウトではない
	else return true;
}


