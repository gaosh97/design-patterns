#include <iostream>

using namespace std;

//ģ��ģʽ

/*
* ����һ���㷨���̣���һЩ�ض�����ľ���ʵ�֡��ӳٵ����ࡣʹ�ÿ����ڲ��ı��㷨���̵�����£�ͨ����ͬ�����ࡢ��ʵ�֡����ơ������е��ض��Ĳ���
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
    //��������Ϊ�ŵ�����ʵ��
    virtual void installCpu() = 0;

    virtual void installRam() = 0;

    virtual void installGraphicsCard() = 0;

private:
    //�����Ĳ��֣�����
    void installHardisk() {
        std::cout << "Computer install 1TB hard disk !" << std::endl;
    };
};

//����ʵ�ָ����������һ���������󷽷�
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
//    //C++14�������make_unique
//    std::unique_ptr<ComputerB> pComputerB = std::unique_ptr<ComputerB>(new ComputerB);
//    pComputerB->product();
//
//    return 0;
//}
