//����һ��������Ʒ����Ĺ����ӿڣ���ʵ�ʴ��������Ƴٵ����൱��
//https://www.cnblogs.com/wzxNote/p/13354686.html
#include <iostream>

class ISpliter
{
public:
	virtual void split() = 0;
	virtual ~ISpliter() {}
};

class SpliterFactory
{
public:
	virtual ISpliter* CreateSpliter() = 0;
	virtual ~SpliterFactory() {}
};


class BinarySpliter : public ISpliter
{
public:

	void split()
	{
		std::cout << "BinarySpliter" << std::endl;
	}
};

class TxtSpliter : public ISpliter
{
public:

	void split()
	{
		std::cout << "TxtSpliter" << std::endl;
	}
};

class PictureSpliter : public ISpliter
{
public:

	void split()
	{
		std::cout << "TxtSpliter" << std::endl;
	}
};

//���幤��
class BinarySpliterFactory : public SpliterFactory
{
public:
	virtual ISpliter* CreateSpliter()
	{
		std::cout << "BinarySpliterFactory" << std::endl;
		return new BinarySpliter();
	}
};

class TxtSpliterFactory : public SpliterFactory
{
public:
	virtual ISpliter* CreateSpliter()
	{
		std::cout << "TxtSpliterFactory" << std::endl;
		return new TxtSpliter();
	}
};

class PictureSpliterFactory : public SpliterFactory
{
public:
	virtual ISpliter* CreateSpliter()
	{
		std::cout << "PictureSpliterFactory" << std::endl;
		return new PictureSpliter();
	}
};

//int main() {
//
//	std::cout << "��������ģʽ" << std::endl;
//	//���幤�������Ͳ�Ʒ�����
//	ISpliter* product = nullptr;
//	SpliterFactory* factory = nullptr;
//
//	factory = new BinarySpliterFactory();
//	product = factory->CreateSpliter();
//	product->split();
//	delete factory;
//	delete product;
//
//
//	factory = new TxtSpliterFactory();
//	product = factory->CreateSpliter();
//	product->split();
//	delete factory;
//	delete product;
//
//	factory = new PictureSpliterFactory();
//	product = factory->CreateSpliter();
//	product->split();
//	delete factory;
//	delete product;
//
//	return 0;
//}

