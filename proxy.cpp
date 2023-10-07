//为其他对象提供一种代理以控制对这个对象的访问
#include <iostream>
class ISubject
{
public:
	virtual void process()
	{
		std::cout << "This is ISubject" << std::endl;
	}
};

class RealSubject : public ISubject
{
public:
	void process() override
	{
		std::cout << "This is RealSubject" << std::endl;
	}
};
class SubjectProxy : public ISubject
{
public:
	SubjectProxy(ISubject* subject):_subject(subject){}
	virtual void process()
	{
		_subject->process();
		std::cout << "This is SubjectProxy" << std::endl;
	}

private:
	ISubject* _subject;
};

//int main()
//{
//	ISubject* sub = new RealSubject();
//
//	ISubject* intermediary = new SubjectProxy(sub);
//
//	intermediary->process();
//	return 0;
//}