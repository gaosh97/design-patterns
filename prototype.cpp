//ͨ���������ж����������¶��󣬶�����ͨ��ʵ������������
#include <iostream>
class ISplliter {
public:
	virtual void split() = 0;
	virtual ISplliter* clone() = 0;	//ͨ����¡�Լ�����������
	virtual ~ISplliter() {}
};

class BinarySpliter : public ISplliter
{
public:
	virtual void split()
	{
		std::cout << "BinarySpliter" << std::endl;
	}
	virtual ISplliter* clone()
	{
		return new BinarySpliter(*this);
	}
};

class TxtSpliter : public ISplliter
{
public:
	virtual void split()
	{
		std::cout << "TxtSpliter" << std::endl;
	}
	virtual ISplliter* clone()
	{
		return new TxtSpliter(*this);
	}
};

//int main()
//{
//	ISplliter* prototype1 = new BinarySpliter();
//	ISplliter* spliter1 = prototype1->clone();
//	spliter1->split();
//
//	ISplliter* prototype2 = new TxtSpliter();
//	ISplliter* spliter2 = prototype2->clone();
//	spliter2->split();
//	return 0;
//}