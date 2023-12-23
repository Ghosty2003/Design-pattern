#include<string>
#include <unordered_map>
#include<iostream>
using namespace std;

// ��Ԫ�ӿ�
class Flower {
public:
    virtual void display(std::string color) const = 0;
    virtual ~Flower() {}  // ���������������ȷ����ȷ�ͷ���Դ
};

// ������Ԫ�࣬��ʾ����Ļ�������
class ConcreteFlower : public Flower {
private:
    std::string name;

public:
    ConcreteFlower(std::string n) : name(n) {}

    void display(std::string color) const override {
        std::cout << "Flower: " << name << ", Color: " << color << std::endl;
    }
};

// ��Ԫ���������𴴽��͹�����Ԫ����
class FlowerFactory {
private:
    std::unordered_map<std::string, Flower*> flowerCache;

public:
    Flower* getFlower(std::string name) {
        // ����Ѿ�������ͬ���ƵĻ��ܶ�����ֱ�ӷ��أ����򴴽�һ���µĶ��󲢻�������
        if (flowerCache.find(name) != flowerCache.end()) {
            return flowerCache[name];
        }
        else {
            Flower* newFlower = new ConcreteFlower(name);
            flowerCache[name] = newFlower;
            return newFlower;
        }
    }

    ~FlowerFactory() {
        // �ͷŻ����е���Դ
        for (auto& pair : flowerCache) {
            delete pair.second;
        }
        flowerCache.clear();
    }
};

int testFlyweight();

