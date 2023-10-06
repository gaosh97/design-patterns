//保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享
#include<iostream>
class Singleton
{
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
 };

Singleton* Singleton::m_instance = nullptr;

//线程非安全
//Singleton* Singleton::getInstance()
//{
//	if (m_instance == nullptr)
//	{
//		m_instance = new Singleton();
//	}
//	return m_instance;
//}


Singleton* Singleton::getInstance()
{
	static Singleton instance;
	return &instance;
}
