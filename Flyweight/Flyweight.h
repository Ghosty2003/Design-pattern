#include<string>
#include <unordered_map>
#include<iostream>
using namespace std;

// 享元接口
class Flower {
public:
    virtual void display(std::string color) const = 0;
    virtual ~Flower() {}  // 添加虚析构函数，确保正确释放资源
};

// 具体享元类，表示具体的花卉类型
class ConcreteFlower : public Flower {
private:
    std::string name;

public:
    ConcreteFlower(std::string n) : name(n) {}

    void display(std::string color) const override {
        std::cout << "Flower: " << name << ", Color: " << color << std::endl;
    }
};

// 享元工厂，负责创建和管理享元对象
class FlowerFactory {
private:
    std::unordered_map<std::string, Flower*> flowerCache;

public:
    Flower* getFlower(std::string name) {
        // 如果已经存在相同名称的花卉对象，则直接返回，否则创建一个新的对象并缓存起来
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
        // 释放缓存中的资源
        for (auto& pair : flowerCache) {
            delete pair.second;
        }
        flowerCache.clear();
    }
};

int testFlyweight();

