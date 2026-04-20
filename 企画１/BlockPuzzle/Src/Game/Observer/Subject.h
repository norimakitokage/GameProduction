#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class CSubject
{
private:
	vector<CObserver*> m_Observers;

public:
	void AddObserver(CObserver* observer);

	void RemoveObserver(CObserver* observer);

	void NotifyObservers();

};

