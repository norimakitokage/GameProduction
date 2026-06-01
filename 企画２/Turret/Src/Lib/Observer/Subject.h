#pragma once
#include "Observer.h"
#include <vector>

using namespace std;

class CSubject
{
private:
	vector<CObserver*> m_Observers;

public:
	// オブザーバーの追加
	void AddObserver(CObserver* observer);

	// オブザーバーの削除
	void RemoveObserver(CObserver* observer);

	// 呼び出し
	void NotifyObservers();

};

