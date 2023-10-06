//��������һ��һ�Զ��������ϵ��ʹ��ÿ��һ������ı�״̬�����������������Ķ��󶼻�õ�֪ͨ���Զ�����
//https://blog.csdn.net/m0_61705102/article/details/128138766

#include <iterator>
#include <memory>
#include<mutex>
#include<iostream>
#include<vector>

class Observer;
typedef std::vector<std::weak_ptr<Observer>>::iterator Iterator;//������

//���󱻹۲���
class Subject
{
public:
    virtual void Attach(std::weak_ptr<Observer>) = 0;//ע��۲��߶���Ľӿ�
    virtual Iterator Detach(Iterator it) = 0;//ɾ���۲��߶���Ľӿ�
    virtual void notifyObservers() = 0;//��֪���й۲���update
};

//����۲���

class Observer
{
public:
    virtual void update() = 0;//��������״̬
};

//���۲���
class ConcreteSubject :public::Subject
{
public:
    void Attach(std::weak_ptr<Observer> s)
    {
        //vector��add���̰߳�ȫ��
        observers_.push_back(s);
    }
    Iterator Detach(Iterator it)
    {
        //�̲߳���ȫ��Ҫ���ٽ������ô˽ӿ�
        return observers_.erase(it);
    }

    void notifyObservers()
    {
        lock.lock();
        Iterator it = observers_.begin();
        while (it != observers_.end())
        {
            //�ȳ��Խ�weak_ptr����Ϊshare_ptr
            std::shared_ptr<Observer>obj = it->lock();
            if (obj)//�����ɹ���˵���ö���δ�������߳�����
            {
                obj->update();//����
                ++it;
            }
            else//����ʧ�ܣ�˵���ö����ѱ������߳�����
            {
                //�ӹ۲��߼����н��ѱ���������ɾ��
                //��Ϊ�˴������ٽ��������̰߳�ȫ��
                it = Detach(it);
            }

        }
        lock.unlock();
    }

private:
    mutable std::mutex lock;
    std::vector<std::weak_ptr<Observer>> observers_;//�۲��߼���

};

//�۲��߰������弴�ɣ���Ҫ�̳г���۲���
//����Ϊ��
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
