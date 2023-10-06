//定义对象间一种一对多的依赖关系，使得每当一个对象改变状态，则所有依赖于它的对象都会得到通知并自动更新
//https://blog.csdn.net/m0_61705102/article/details/128138766

#include <iterator>
#include <memory>
#include<mutex>
#include<iostream>
#include<vector>

class Observer;
typedef std::vector<std::weak_ptr<Observer>>::iterator Iterator;//迭代器

//抽象被观察者
class Subject
{
public:
    virtual void Attach(std::weak_ptr<Observer>) = 0;//注册观察者对象的接口
    virtual Iterator Detach(Iterator it) = 0;//删除观察者对象的接口
    virtual void notifyObservers() = 0;//告知所有观察者update
};

//抽象观察者

class Observer
{
public:
    virtual void update() = 0;//更新自身状态
};

//被观察者
class ConcreteSubject :public::Subject
{
public:
    void Attach(std::weak_ptr<Observer> s)
    {
        //vector的add是线程安全的
        observers_.push_back(s);
    }
    Iterator Detach(Iterator it)
    {
        //线程不安全，要在临界区调用此接口
        return observers_.erase(it);
    }

    void notifyObservers()
    {
        lock.lock();
        Iterator it = observers_.begin();
        while (it != observers_.end())
        {
            //先尝试将weak_ptr提升为share_ptr
            std::shared_ptr<Observer>obj = it->lock();
            if (obj)//提升成功，说明该对象未被其他线程析构
            {
                obj->update();//更新
                ++it;
            }
            else//提升失败，说明该对象已被其他线程析构
            {
                //从观察者集合中将已被析构对象删除
                //因为此处属于临界区，是线程安全的
                it = Detach(it);
            }

        }
        lock.unlock();
    }

private:
    mutable std::mutex lock;
    std::vector<std::weak_ptr<Observer>> observers_;//观察者集合

};

//观察者按需求定义即可，需要继承抽象观察者
//以下为例
class Teacher :public::Observer
{
public:
    void update()
    {
        std::cout << "Teacher is update" << std::endl;
    }
    ~Teacher()
    {
        std::cout << "Teacher is ~" << std::endl;
    }
};

class Student :public::Observer
{
public:
    void update()
    {
        std::cout << "Student is update" << std::endl;
    }
    ~Student()
    {
        std::cout << "Student is ~" << std::endl;
    }
};

//int main()
//{
//
//    ConcreteSubject subject;
//
//    std::shared_ptr<Observer> teacher(new Teacher);
//    subject.Attach(teacher);
//
//    {
//        std::shared_ptr<Observer> student(new Student);
//        subject.Attach(student);
//        subject.notifyObservers();
//    }
//
//    subject.notifyObservers();
//
//}
