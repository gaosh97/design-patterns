//表示一个作用于某对象结构的各元素的操作
//它使你可以再不改变各元素的类的前提下定义作用于这些元素的新操作

//俩个类相互引用，使用前向声明
//只能用于定义指针、引用、以及用于函数形参的指针和引用
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