#pragma once
#include "Object.h"

class CActor : public CObject {
protected:
	//アニメーション再生に必要なデータ
	typedef struct {
		float m_frame;		//再生中のアニメのフレーム
		float m_endFrame;	//再生中アニメの最後のフレーム
		float m_speed;		//アニメの再生速度
		int m_hndl;			//アニメーション用のハンドル
		int m_id;			//アニメーション番号
		int m_state;		//ループするか、最後で止めるか
		int m_isStop;		//ストップするかどうか
	}ANIM_DATA;

	ANIM_DATA m_animData;
public:
	//コンストラクタ・デストラクタ
	CActor();
	//virtual ~CActor();

	//初期化
	virtual void Init() override;
	//更新処理
	virtual void Update() override;

	//アニメリクエスト
	// animId		:	アタッチするアニメ番号
	// animSpd		:	アニメ再生速度
	// animSrcHndl	:	アニメーションを持っているハンドル(-1ならばこのモデルのアニメ使用)
	// NamaCheck	:	別モデルのアニメを使用する場合、モデルのフレーム名が一致していない場合
	//					アニメをアタッチするか(abunSrcHndl=-1の場合は無視)
	void Request(int animId, float animSpd, int animSrcHndl = -1, bool NameCheck = false);
	//	ループアニメリクエスト
	//	終わったら最初から再生される
	void RequestLoop(int animId, float animSpd, int animSrcHndl = -1, bool NameCheck = false);
	//　エンドループリクエスト
	//　終わったら最終フレームで止まる
	void RequestEndLoop(int animId, float animSpd, int animSrcHndl = -1, bool NameCheck = false);

	//アニメーションの停止
	void StopAnimation();
	//アニメーションの再生
	void PlayAnimation();
	void PlayAnimation(float frame);

	//アニメーション経過時間取得
	float GetAnimTime();

	//再生中のアニメーションID取得
	int GetAnimID();

	//アニメーションの消去
	void DetachAnim();

	//アニメが終わったか判定
	bool IsEndAnim();
};
