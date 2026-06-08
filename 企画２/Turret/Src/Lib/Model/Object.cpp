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
	m_Pos = { 0.0f,0.0f,0.0f };
	m_Rot = { 0.0f,0.0f,0.0f };
	m_Scale = { 1.0f,1.0f,1.0f };
	m_Hndl = -1;
}

//終了処理
void CObject::Exit() {
	DeleteModel();
	m_Hndl = -1;
}

//描画処理
void CObject::Draw() {
	MV1DrawModel(m_Hndl);
}

//更新処理
void CObject::Update() {
	// 位置・角度・拡縮
	MV1SetPosition(m_Hndl, m_Pos);
	MV1SetRotationXYZ(m_Hndl, m_Rot);
	MV1SetScale(m_Hndl, m_Scale);
}

//モデルのロード
void CObject::LoadModel(const char* Path) {
	if (m_Hndl != -1) return;
	m_Hndl = MV1LoadModel(Path);

}

//モデルの複製
void CObject::LoadDuplicateModel(int OrgHndl) {
	if (m_Hndl != -1) return;
	m_Hndl = MV1DuplicateModel(OrgHndl);
}



//モデルの削除
void CObject::DeleteModel() {
	if (m_Hndl != -1) {
		MV1DeleteModel(m_Hndl);
	}
}



void CObject::SetPosition(VECTOR pos)
{
	m_Pos = pos;
}

VECTOR CObject::GetPosition()
{
	return m_Pos;
}

void CObject::SetRotation(VECTOR rot)
{
	m_Rot = rot;
}

VECTOR CObject::GetRotation()
{
	return m_Rot;
}

void CObject::SetScale(VECTOR scale)
{
	m_Scale = scale;
}

VECTOR CObject::GetScale()
{
	return m_Scale;
}
