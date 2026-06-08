#include "Player.h"

const VECTOR PLAYER_MODEL_SIZE = VGet(0.008f, 0.008f, 0.008f);

void CPlayer::Init()
{
	CActor::Init();
	this->SetScale(PLAYER_MODEL_SIZE);
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
