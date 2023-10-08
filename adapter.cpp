//STL里stack和queue使用deque 
#include <iostream>

class ITareget
{
public:
	virtual void process() = 0;
};

class IAdaptee
{
public:
	virtual void foo(int data)
	{
		std::cout << data << std::endl;
	}
	virtual int bar()
	{
		std::cout << "被适配" << std::endl;
		return sizeof(int);
	}
};

class Adapter : public ITareget
{
	IAdaptee* pAdaptee;
public:
	Adapter(IAdaptee* ppAdapter)
	{
		pAdaptee = ppAdapter;
	}
	virtual void process()
	{
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};

//int main()
//{
//	IAdaptee* pAdapter = new IAdaptee();
//	ITareget* pTarget = new Adapter(pAdapter);
//	pTarget->process();
//}