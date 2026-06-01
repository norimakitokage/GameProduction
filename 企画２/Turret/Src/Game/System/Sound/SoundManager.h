#pragma once
#include <DxLib.h>
#include <vector>

using namespace std;

class CSoundManager {
public:
	enum tagSoundId{
		BGM_GAME,		//BGM ゲーム本編
		SE_SHOT,		//SE 弾の発射
		SE_EXPLOSION,	//SE 爆発音
		BGM_TITLE,		//タイトル
		BGM_CLEAR,		//クリア
		BGM_FAIL,		//失敗

		SOUND_NUM
	};
private:
	static vector<int>m_hndl;	//音楽ハンドル

public:
	CSoundManager();

	//初期化
	static void Init();
	//終了
	static void Exit();
	//読み込み
	static void LoadAllData();

	//音楽の再生
	// ＠isStart：ture 最初から再生
	//			：false 中断したところから再生
	static bool Play(tagSoundId id, int type = DX_PLAYTYPE_BACK, bool isStart = true);
	//音楽停止
	static void Stop(tagSoundId id);
	//すべての音楽停止
	static void StopAll();
	
	//音楽が流れているか
	static bool IsPlay(tagSoundId id);

	//再生した音楽の経過時間を取得
	static int GetSoundTime(tagSoundId id);
	//再生する音楽の総再生時間を取得
	static int GetSoundAllTime(tagSoundId id);

	//再生開始時間の指定
	static void SetStartFrame(tagSoundId id, int ms);
	//音楽のボリューム設定
	static void SetVolume(tagSoundId id, float fVol);


};
