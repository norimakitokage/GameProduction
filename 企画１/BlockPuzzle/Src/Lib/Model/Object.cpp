#include "Object.h"

//コンストラクタ
CObject::CObject() {
	Init();
}

//デストラクタ
CObject::~CObject() {
	Exit();
}

//初期化
void CObject::Init() {
	m_pos = { 0.0f,0.0f,0.0f };
	m_rot = { 0.0f,0.0f,0.0f };
	m_scale = { 1.0f,1.0f,1.0f };
	m_hndl = -1;
}

//終了処理
void CObject::Exit() {
	DeleteModel();
	m_hndl = -1;
}

//描画処理
void CObject::Draw() {
	MV1DrawModel(m_hndl);
}

//更新処理
void CObject::Update() {
	// 位置・角度・拡縮
	MV1SetPosition(m_hndl, m_pos);
	MV1SetRotationXYZ(m_hndl, m_rot);
	MV1SetScale(m_hndl, m_scale);
}

//モデルのロード
void CObject::LoadModel(const char* Path) {
	if (m_hndl != -1) return;
	m_hndl = MV1LoadModel(Path);

}

//モデルの複製
void CObject::LoadDuplicateModel(int OrgHndl) {
	if (m_hndl != -1) return;
	m_hndl = MV1DuplicateModel(OrgHndl);
}



//モデルの削除
void CObject::DeleteModel() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);
	}
}
