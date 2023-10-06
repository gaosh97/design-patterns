//通过复制已有对象来创建新对象，而不是通过实例化类来创建
#include <iostream>
class ISplliter {
public:
	virtual void split() = 0;
	virtual ISplliter* clone() = 0;	//通过克隆自己来创建对象
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