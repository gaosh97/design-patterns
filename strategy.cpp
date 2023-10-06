#include <algorithm>
#include <iostream>
using namespace std;

//策略模式

/*
* 使不同的算法可以被相互替换，而不影响客户端的使用
*/

//用if else判断实现违背开闭原则
//Strategt类，定义所有支持的算法的公共接口
class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
    virtual ~Strategy() {};
    
};

//ConcreteStrategy 封装了具体的算法或行为，继承Strategy
class ConcreteStrategyA : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "算法A实现" << endl;
    }
};

class ConcreteStrategyB : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "算法B实现" << endl;
    }
};

class ConcreteStrategyC : public Strategy {
    virtual void AlgorithmInterface() {
        cout << "算法C实现" << endl;
    }
};

//Context,用一个ConcreteStrategy来配置,维护一个对Strategy的引用
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