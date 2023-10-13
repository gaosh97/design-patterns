//提供一个对象来顺序访问聚合对象中的一系列数据，而不暴露聚合对象的内部表示
//https://blog.csdn.net/MrHHHHHH/article/details/133655392
#include <iostream>
#include <vector>
// 迭代器接口
class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() const = 0;
    virtual int next() = 0;
};

// 具体迭代器
class MyIterator : public Iterator {
public:
    MyIterator(const std::vector<int>& collection) : collection(collection), index(0) {}
    bool hasNext() const {
        return index < collection.size();
    }
    int next() {
        return collection[index++];
    }

private:
    const std::vector<int>& collection;
    int index;
};

// 聚合对象
class MyCollection {
public:
    Iterator* createIterator() const {
        return new MyIterator(elements);
    }
    void addElement(int element) {
        elements.push_back(element);
    }

private:
    std::vector<int> elements;
};

// 客户端
//int main() {
//    MyCollection myCollection;
//    myCollection.addElement(1);
//    myCollection.addElement(2);
//    myCollection.addElement(3);
//
//    Iterator* iterator = myCollection.createIterator();
//    while (iterator->hasNext()) {
//        std::cout << iterator->next() << " ";
//    }
//    std::cout << std::endl;
//
//    delete iterator;
//    return 0;
//}
