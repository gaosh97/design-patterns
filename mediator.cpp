//用一个中介对象来封装一系列的对象。
//中介者使各对象不需要显示地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
//https://blog.csdn.net/naibozhuan3744/article/details/108927422
#include <iostream>
#include <vector>

class Colleague;

class IMediator
{
protected:
	std::vector<Colleague*> colleagues;

public:
	IMediator() :colleagues(0) {}
	virtual ~IMediator() {}

	virtual void add(Colleague* colleague) = 0;
	virtual void send(Colleague* colleague) = 0;
};

class Colleague
{
protected:
	IMediator* mediator;
public:
	Colleague(IMediator* mediator) :mediator(mediator) {}
	virtual void notify() = 0;
	virtual void send() = 0;
};

class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(IMediator* mediator) : Colleague(mediator) {}
	virtual void notify()
	{
		std::cout << "This is ConcreteColleague1" << std::endl;
	}
	virtual void send()
	{
		mediator->send(this);
	}
};

class ConcreteColleague2 : public Colleague
{
public:
	ConcreteColleague2(IMediator* mediator) : Colleague(mediator) {}
	virtual void notify()
	{
		std::cout << "This is ConcreteColleague2" << std::endl;
	}
	virtual void send()
	{
		mediator->send(this);
	}
};

class ConcreteMediator : public IMediator
{
public:
	void add(Colleague* colleague) override
	{
		colleagues.emplace_back(colleague);
	}
	void send(Colleague* colleague) override
	{
		for (const auto& it : colleagues)
		{
			if (it == colleague)
			{
				it->notify();
				break;
			}
		}
	}
};

//int main()
//{
//	IMediator* mediator = new ConcreteMediator();
//	Colleague* colleague1 = new ConcreteColleague1(mediator);
//	Colleague* colleague2 = new ConcreteColleague2(mediator);
//	mediator->add(colleague1); // 中介者把同事加入同事集合
//	mediator->add(colleague2);
//
//	colleague1->send(); // 租客在中介者发布租房信息
//	colleague2->send(); // 房东也在中介者发布出租房信息
//}
