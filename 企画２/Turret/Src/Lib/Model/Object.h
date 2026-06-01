#pragma once
#include <DxLib.h>

//3Dモデル操作クラス
class CObject {
protected:
	VECTOR m_pos;		//座標
	VECTOR m_rot;		//回転
	VECTOR m_scale;		//拡縮
	int m_hndl;			//モデルのハンドル
	

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

};
