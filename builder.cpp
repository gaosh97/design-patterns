//��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
//https://blog.csdn.net/naibozhuan3744/article/details/108230453
#include <iostream>
#include <string>

using namespace std;

#define DELETE(pointer) delete pointer; pointer=nullptr

class IProduct { //�����Ʒ��
public:
	virtual string& getName() = 0;
	virtual void show() = 0;
};

class Product1 : public IProduct { //�����Ʒ��
public:
	string& getName() override { return name; }
	void show() override { cout << "name==" << name << endl; }

private:
	string name; //Ҫ�����ľ����Ʒ���֣���Ϊ���������ܹ�����ϣ�
};

class IBuilder
{
public:
	IBuilder() {}
	virtual ~IBuilder() {}

	virtual void buildPart1() = 0;
	virtual void buildPart2() = 0;
	virtual IProduct* getProduuct() = 0;
};

class ConcreteBuilder : public IBuilder //��������ṹ��ϸ�ڵľ���ʵ�ֻ���˵��ʾ��
{
public:
	ConcreteBuilder(IProduct* product) : product(product) {}
	~ConcreteBuilder() {}

	void buildPart1() override { product->getName().append("buildPart1+"); }
	void buildPart2() override { product->getName().append("buildPart2"); }
	IProduct* getProduuct() override { return product; }

private:
	IProduct* product;
};

class Director //�����ߣ��ñ�ʾ���ϸ��ʵ�ֽӿں�������һ���߼���ϳ�ĳһ���Ʒ
{
public:
	Director() {}
	~Director() {}


	IProduct* construct(IBuilder* builder) { //����ָ��ΨһĿ���ǶԸö�����й���������ǰ��ָ���ַһֱ����
		builder->buildPart1();
		builder->buildPart2();
		return builder->getProduuct();
	}
};

void doBuilderPattern()
{
	IProduct* product = new Product1(); //����һ����ʼ���Ĳ�Ʒ
	IBuilder* builder = new ConcreteBuilder(product); //�����������������Ʒ�����ַ׼����������Ʒ�͹���
	Director().construct(builder); //���������Ʒ�͹���
	product->show();
	DELETE(builder);
	DELETE(product);
}

//int main()
//{
//	doBuilderPattern();
//
//	system("pause");
//	return 1;
//}