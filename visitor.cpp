//��ʾһ��������ĳ����ṹ�ĸ�Ԫ�صĲ���
//��ʹ������ٲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²���

//�������໥���ã�ʹ��ǰ������
//ֻ�����ڶ���ָ�롢���á��Լ����ں����βε�ָ�������
#include <string>
#include <iostream>
class ElementA;
class ElementB;

class Visitor
{
public:
	virtual void VisitElementA(ElementA& element) = 0;
	virtual void VisitElementB(ElementB& element) = 0;
	virtual ~Visitor() {}
};

class Visitor1 : public Visitor
{
public:
	void VisitElementA(ElementA& element) override
	{
		std::cout << "Visitor1 is processing ElementA" << std::endl;
	}
	void VisitElementB(ElementB& element) override
	{
		std::cout << "Visitor1 is processing ElementB" << std::endl;
	}
};
class Visitor2 : public Visitor
{
public:
	void VisitElementA(ElementA& element) override
	{
		std::cout << "Visitor2 is processing ElementA" << std::endl;
	}
	void VisitElementB(ElementB& element) override
	{
		std::cout << "Visitor2 is processing ElementB" << std::endl;
	}
};


class Element
{
public:
	virtual void accept(Visitor& visitor) = 0;
	virtual ~Element() {}
};

class ElementA : public Element
{
public:
	void accept(Visitor& visitor) override
	{
		visitor.VisitElementA(*this);
	}
};

class ElementB : public Element
{
public:
	void accept(Visitor& visitor) override
	{
		visitor.VisitElementB(*this);
	}
};


//int main()
//{
//	Visitor2 visitor;
//	ElementB element;
//	element.accept(visitor);
//
//	ElementA elementA;
//	elementA.accept(visitor);
//}