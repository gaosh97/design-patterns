//��֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㣬��ʵ�������г���ģ�鹲��
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

//�̷߳ǰ�ȫ
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
