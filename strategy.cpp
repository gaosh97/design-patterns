#include <algorithm>
#include <iostream>
using namespace std;

//����ģʽ

/*
* ʹ��ͬ���㷨���Ա��໥�滻������Ӱ��ͻ��˵�ʹ��
*/

//��if else�ж�ʵ��Υ������ԭ��
//Strategt�࣬��������֧�ֵ��㷨�Ĺ����ӿ�
class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
    virtual ~Strategy() {};
    
};

//ConcreteStrategy ��װ�˾�����㷨����Ϊ���̳�Strategy
class ConcreteStrategyA : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "�㷨Aʵ��" << endl;
    }
};

class ConcreteStrategyB : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "�㷨Bʵ��" << endl;
    }
};

class ConcreteStrategyC : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "�㷨Cʵ��" << endl;
    }
};

//Context,��һ��ConcreteStrategy������,ά��һ����Strategy������
class Context {
public:
    Context(Strategy* strategy)
    {
        this->m_strategy = strategy;
    };

    ~Context() 
    {
        if (m_strategy)
        {
            delete this->m_strategy;
        }
        m_strategy = nullptr;
    }
    void DoAction() {
        this->m_strategy->AlgorithmInterface();
    };
private:
    Strategy* m_strategy;
};


//int main() {
//    Strategy* pStr = new ConcreteStrategyA();
//    Context* pCon = new Context(pStr);
//    pCon->DoAction();
//
//    return 0;
//}