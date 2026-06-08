#pragma once

//フェードの状態遷移
enum tagFadeState {
	FADE_NON,				//フェードなし
	FADE_IN,				//フェードイン中
	FADE_OUT,				//フェードアウト中
	FADE_OUT_WAIT,			//フェードアウト後の真っ暗な状態
};

class CFade {
private:
	static tagFadeState m_id;
	static int m_count;

public:
	static void Init();	//フェードの初期化
	static void Load();	//フェードのロード（画像を差し込むとき）
	static void Step();	//フェードの更新処理
	static void Draw();	//フェードの画像描画
	static void Exit();	//フェードの削除（画像を差し込むとき）

	//フェードインリクエスト
	static void RequestFadeIn();
	//フェードアウトリクエスト
	static void RequestFadeOut();
	//フェードインが終了したか
	static bool IsEndFadeIn();
	//フェードアウトが終了したか
	static bool IsEndFadeOut();

	//現在の状態を取得
	static tagFadeState GetFadeId() { return m_id; }

	//セットする
	static void SetId(tagFadeState id) {
		m_id = id;
	}
	static void SetCount(int count) {
		m_count = count;
	}
};

