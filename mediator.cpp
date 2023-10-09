//��һ���н��������װһϵ�еĶ���
//�н���ʹ��������Ҫ��ʾ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����
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
//	mediator->add(colleague1); // �н��߰�ͬ�¼���ͬ�¼���
//	mediator->add(colleague2);
//
//	colleague1->send(); // ������н��߷����ⷿ��Ϣ
//	colleague2->send(); // ����Ҳ���н��߷������ⷿ��Ϣ
//}
