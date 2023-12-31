//提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类
#include <iostream>
using namespace std;

// Product A
class ProductA
{
public:
    virtual void Show() = 0;
};

class ProductA1 : public ProductA
{
public:
    void Show()
    {
        cout << "I'm ProductA1" << endl;
    }
};

class ProductA2 : public ProductA
{
public:
    void Show()
    {
        cout << "I'm ProductA2" << endl;
    }
};

// Product B
class ProductB
{
public:
    virtual void Show() = 0;
};

class ProductB1 : public ProductB
{
public:
    void Show()
    {
        cout << "I'm ProductB1" << endl;
    }
};

class ProductB2 : public ProductB
{
public:
    void Show()
    {
        cout << "I'm ProductB2" << endl;
    }
};

// Factory
class Factory
{
public:
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
};

class Factory1 : public Factory
{
public:
    ProductA* CreateProductA()
    {
        return new ProductA1();
    }

    ProductB* CreateProductB()
    {
        return new ProductB1();
    }
};

class Factory2 : public Factory
{
    ProductA* CreateProductA()
    {
        return new ProductA2();
    }

    ProductB* CreateProductB()
    {
        return new ProductB2();
    }
};

//int main(int argc, char* argv[])
//{
//    Factory* factoryObj1 = new Factory1();
//    ProductA* productObjA1 = factoryObj1->CreateProductA();
//    ProductB* productObjB1 = factoryObj1->CreateProductB();
//
//    productObjA1->Show();
//    productObjB1->Show();
//
//    Factory* factoryObj2 = new Factory2();
//    ProductA* productObjA2 = factoryObj2->CreateProductA();
//    ProductB* productObjB2 = factoryObj2->CreateProductB();
//
//    productObjA2->Show();
//    productObjB2->Show();
//
//    if (factoryObj1 != NULL)
//    {
//        delete factoryObj1;
//        factoryObj1 = NULL;
//    }
//
//    if (productObjA1 != NULL)
//    {
//        delete productObjA1;
//        productObjA1 = NULL;
//    }
//
//    if (productObjB1 != NULL)
//    {
//        delete productObjB1;
//        productObjB1 = NULL;
//    }
//
//    if (factoryObj2 != NULL)
//    {
//        delete factoryObj2;
//        factoryObj2 = NULL;
//    }
//
//    if (productObjA2 != NULL)
//    {
//        delete productObjA2;
//        productObjA2 = NULL;
//    }
//
//    if (productObjB2 != NULL)
//    {
//        delete productObjB2;
//        productObjB2 = NULL;
//    }
//}