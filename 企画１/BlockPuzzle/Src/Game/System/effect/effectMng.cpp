#include "effectMng.h"

static const char* EFFECT_PATH[ALL_EFFECT] = {
	"",

};

void CEffectMng::Init() {
	CEffekseerCtrl::Init(50, 3000);
}

void CEffectMng::Load() {
	for (int i = 0; i < ALL_EFFECT; i++) {
		CEffekseerCtrl::LoadData(EFFECT_PATH[i]);
	}
}

void CEffectMng::Step() {
	CEffekseerCtrl::SetAutoCameraMtx();
	CEffekseerCtrl::SetAutoProjectionMtx();
	CEffekseerCtrl::Update();
}

void CEffectMng::Draw() {
	CEffekseerCtrl::Draw();
}

void CEffectMng::Exit() {
	CEffekseerCtrl::Exit();
}

//IDと場所とループするかをセット
void CEffectMng::Request(int ID, VECTOR Pos, bool Loop) {
	CEffekseerCtrl::Request(ID, Pos, Loop);
}

