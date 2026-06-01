#include "Singleton.h"

CSingleton* CSingleton::m_Instance = nullptr;

CSingleton* CSingleton::GetInstance()
{
	if (m_Instance == nullptr) {
		m_Instance = new CSingleton;
	}
	return m_Instance;
}

void CSingleton::DeleteInstance()
{
	if (m_Instance != nullptr) {
		delete m_Instance;
		m_Instance = nullptr;
	}
}
