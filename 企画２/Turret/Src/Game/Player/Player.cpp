#include "Player.h"



void CPlayer::Init()
{
	CActor::Init();

}

void CPlayer::Load()
{
	LoadModel("Data/Player/Turret.mv1");
}

void CPlayer::Step()
{
}

void CPlayer::Update()
{
	CObject::Update();
}

void CPlayer::Exit()
{
	CObject::DeleteModel();
}

void CPlayer::Draw()
{
	CObject::Draw();
}
