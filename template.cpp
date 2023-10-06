#include <iostream>

using namespace std;

//模板模式

/*
* 定义一个算法流程，将一些特定步骤的具体实现、延迟到子类。使得可以在不改变算法流程的情况下，通过不同的子类、来实现“定制”流程中的特定的步骤
*/
class Computer {
public:
    void product() {
        installCpu();
        installRam();
        installGraphicsCard();
        installHardisk();
    }

    virtual ~Computer() = default;

protected:
    //将抽象行为放到子类实现
    virtual void installCpu() = 0;

    virtual void installRam() = 0;

    virtual void installGraphicsCard() = 0;

private:
    //公共的部分，不变
    void installHardisk() {
        std::cout << "Computer install 1TB hard disk !" << std::endl;
    };
};

//子类实现父类所定义的一个或多个抽象方法
class ComputerA : public Computer {
protected:
    void installCpu() override {
        cout << "ComputerA install Inter Core i5" << endl;
    }

    void installRam() override {
        cout << "ComputerA install 2G Ram" << endl;
    }

    void installGraphicsCard() override {
        cout << "ComputerA install Gtx940 GraphicsCard" << endl;
    }
};

class ComputerB : public Computer {
protected:
    void installCpu() override {
        cout << "ComputerB install Inter Core i7" << endl;
    }

    void installRam() override {
        cout << "ComputerB install 4G Ram" << endl;
    }

    void installGraphicsCard() override {
        cout << "ComputerB install Gtx960 GraphicsCard" << endl;
    }
};

//int main() {
//    std::shared_ptr<Computer> pComputerA = std::make_shared<ComputerA>();
//    pComputerA->product();
//
//    //C++14才引入进make_unique
//    std::unique_ptr<ComputerB> pComputerB = std::unique_ptr<ComputerB>(new ComputerB);
//    pComputerB->product();
//
//    return 0;
//}
