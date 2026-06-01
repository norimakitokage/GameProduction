#pragma once

class CSingleton
{
protected:
	// 生成するインスタンス
	static CSingleton* m_Instance;

public:
	// インスタンスの取得
	static CSingleton* GetInstance();
	// インスタンスの削除
	static void DeleteInstance();
};
