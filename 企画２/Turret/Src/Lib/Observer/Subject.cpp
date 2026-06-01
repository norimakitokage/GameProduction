#include "Subject.h"

void CSubject::AddObserver(CObserver* observer)
{
	m_Observers.push_back(observer);
}

void CSubject::RemoveObserver(CObserver* observer)
{
	m_Observers.erase(remove(m_Observers.begin(), m_Observers.end(), observer), m_Observers.end());
}

void CSubject::NotifyObservers()
{
	for (CObserver* obserber : m_Observers) {
		obserber->Update();
	}
}
