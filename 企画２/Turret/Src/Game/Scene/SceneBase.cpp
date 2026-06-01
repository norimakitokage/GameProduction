#include "SceneBase.h"

CSceneBase::CSceneBase()
{
	m_State = INIT;
}

CSceneBase::~CSceneBase()
{
}

void CSceneBase::Loop()
{
	void (CSceneBase:: * scene[])() = { &CSceneBase::Init, &CSceneBase::Load, &CSceneBase::StartWait,
	& CSceneBase::Step, & CSceneBase::Update, & CSceneBase::EndWait, & CSceneBase::Exit };

	(this->*scene[m_State])();
}


