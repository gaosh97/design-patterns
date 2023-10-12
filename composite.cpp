//ͨ����Ϲ�ϵ�������Ĺ�����ϵ��ʵ���˽�������ϳ����νṹ������ʵ����ĸ���
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class Componet
{
public:
	virtual void process() = 0;
	virtual ~Componet() {}
};

class Composite : public Componet
{
	std::string name;
	std::list<Componet*> elements;

public:
	Composite(const std::string& s) : name(s)
	{
		std::cout << "Composite Construct!" << std::endl;
	}

	void add(Componet* element)
	{
		elements.emplace_back(element);
	}
	void remove(Componet* element)
	{
		elements.remove(element);
	}
	void process()
	{
		std::cout << "This is Composite!" << std::endl;
		for (const auto& e : elements)
		{
			e->process();
		}
	}
};

class Leaf : public Componet
{
	std::string name;
public:
	Leaf(std::string s) :name(s)
	{
		std::cout << "Leaf Construct!" << std::endl;
	}
	void process()
	{
		std::cout << "This is leaf!" << std::endl;
	}
};


//int main()
//{
//	Composite root("root");
//	Composite treeNode1("treeNode1");
//	Composite treeNode2("treeNode2");
//	Composite treeNode3("treeNode3");
//	Composite treeNode4("treeNode4");
//
//	Leaf left1("left1");
//	Leaf left2("left2");
//
//	root.add(&treeNode1);
//	treeNode1.add(&treeNode2);
//	treeNode2.add(&left1);
//
//	root.add(&treeNode3);
//	treeNode3.add(&treeNode4);
//	treeNode4.add(&left2);
//
//	root.process();
//}