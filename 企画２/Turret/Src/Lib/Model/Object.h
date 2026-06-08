#pragma once
#include <DxLib.h>

//3Dモデル操作クラス
class CObject {
protected:
	VECTOR m_Pos;		//座標
	VECTOR m_Rot;		//回転
	VECTOR m_Scale;		//拡縮
	int m_Hndl;			//モデルのハンドル
	

public:
	CObject();
	virtual ~CObject();

	//初期化
	virtual void Init();
	//終了処理
	virtual void Exit();
	//上書き処理
	virtual void Update();
	//描画処理
	virtual void Draw();
	
	//モデルデータロード
	void LoadModel(const char* Path);
	//モデルコピーロード
	void LoadDuplicateModel(int OrgHndl);
	//モデル削除
	void DeleteModel();

public:
	// 座標のゲッター・セッター
	void SetPosition(VECTOR pos);

	VECTOR GetPosition();

	// 回転のゲッター・セッター
	void SetRotation(VECTOR rot);

	VECTOR GetRotation();

	// 拡縮のゲッター・セッター
	void SetScale(VECTOR scale);

	VECTOR GetScale();

};
