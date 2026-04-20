#include "soundManager.h"

//
vector<int> CSoundManager::m_hndl;

CSoundManager::CSoundManager() {
	Init();
}

//‰Šú‰»
void CSoundManager::Init() {
	//’†g‚ğ‹ó‚É‚·‚é
	m_hndl.clear();
}

//“Ç‚İ‚İ
void CSoundManager::LoadAllData() {
	const char* filePath[SOUND_NUM]{
		"data/sound/play.mp3",
		"data/sound/se_plshot.mp3",
		"data/sound/se_explore.mp3",
		"data/sound/title.mp3",
		"data/sound/clear.mp3",
		"data/sound/fail.mp3",
	};

	for (int i = 0; i < SOUND_NUM; i++) {
		int hndl = LoadSoundMem(filePath[i]);
		m_hndl.push_back(hndl);
	}
	
}

//I—¹
void CSoundManager::Exit() {
	for (int i = 0; i < m_hndl.size(); i++) {
		if (m_hndl[i] != -1) {
			DeleteSoundMem(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}

bool CSoundManager::Play(tagSoundId id, int type, bool isStart) {
	int ret = PlaySoundMem(m_hndl[id], type, isStart);
	if (ret == -1) return false;
	else return true;
}

bool CSoundManager::IsPlay(tagSoundId id) {
	return CheckSoundMem(m_hndl[id]) == 1 ? true : false;
	
	/*if (res == 1) return true;
	else return false;*/
}

void CSoundManager::Stop(tagSoundId id) {
	StopSoundMem(m_hndl[id]);
}

void CSoundManager::StopAll() {
	for (int i = 0; i < SOUND_NUM; i++) {
		StopSoundMem(m_hndl[i]);
	}
}

int CSoundManager::GetSoundTime(tagSoundId id) {
	return GetSoundCurrentTime(m_hndl[id]);
}

int CSoundManager::GetSoundAllTime(tagSoundId id) {
	return GetSoundTotalTime(m_hndl[id]);
}

void CSoundManager::SetStartFrame(tagSoundId id, int ms) {
	int iFreq = GetFrequencySoundMem(m_hndl[id]) * ms / 100;
	SetCurrentPositionSoundMem(iFreq, m_hndl[id]);
}

void CSoundManager::SetVolume(tagSoundId id, float fVol) {
	if (fVol < 0.0f || fVol > 1.0f) return;
	ChangeVolumeSoundMem((int)(255.0f * fVol), m_hndl[id]);
}




