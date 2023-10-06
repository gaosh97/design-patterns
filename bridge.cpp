//�����󲿷ֺ�ʵ�ֲ��ַ��룬ʹ���ǿ��Զ����ı仯
//����仯ά�ȣ���ͬƽ̨�Ͳ�ͬ����
#include<string>
#include<iostream>

class MessagerImp;
class Messager
{
public:
	MessagerImp* messagerImp;

	Messager(MessagerImp* mimp) :messagerImp(mimp)
	{

	}
	virtual void Login(std::string username, std::string password) = 0;
	virtual void SendMessage(std::string message) = 0;

	virtual ~Messager() {}
};

class MessagerImp
{
public:
	virtual void PlaySound() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}
};

//ƽ̨ʵ��
class PCMessagerImp : public MessagerImp
{
public:
	
	virtual void PlaySound()
	{
		std::cout << "PC PlaySound" << std::endl;
	}
	virtual void WriteText()
	{
		std::cout << "PC WriteText" << std::endl;
	}
	virtual void Connect()
	{
		std::cout << "PC Connect" << std::endl;
	}
};

class MobileMessagerImp :public MessagerImp
{
public:
	virtual void PlaySound()
	{
		std::cout << "Mobile PlaySound" << std::endl;
	}
	virtual void WriteText()
	{
		std::cout << "Mobile WriteText" << std::endl;
	}
	virtual void Connect()
	{
		std::cout << "Mobile Connect" << std::endl;
	}
};

class MessagerLite : public Messager
{
	
public:
	MessagerLite(MessagerImp* mimp) :Messager(mimp)
	{

	}
	virtual void Login(std::string username, std::string password)
	{
		messagerImp->Connect();
	}
	virtual void SendMessage(std::string message)
	{
		messagerImp->WriteText();
	}
};

class MessagerPerfect : public Messager
{
public:
	MessagerPerfect(MessagerImp* mimp) :Messager(mimp)
	{

	}
	virtual void Login(std::string username, std::string password)
	{
		messagerImp->Connect();
		messagerImp->PlaySound();
	}
	virtual void SendMessage(std::string message)
	{
		messagerImp->WriteText();
		messagerImp->PlaySound();
	}
};

//int main()
//{
//	MessagerImp* mImp = new PCMessagerImp();
//	Messager* m = new MessagerLite(mImp);
//	m->Login("g", "s");
//	m->SendMessage("hello");
//
//	//
//	MessagerImp* mImp2 = new MobileMessagerImp();
//	Messager* m2= new MessagerLite(mImp2);
//	m2->Login("g", "s");
//	m2->SendMessage("hello");
//}