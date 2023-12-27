#pragma once
#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>

using namespace std;

// 花束接口
class IBouquet {
public:
    virtual void deliver(std::string address) = 0;
};

// 花店类
class Flowershop : public IBouquet {
public:
    void deliver(std::string address) override;
};

// 送货代理类
class DeliveryProxy : public IBouquet {
private:
    Flowershop* flowerShop;
public:
    DeliveryProxy();
    void deliver(std::string address) override;
};

// 抽象工厂模式

// 前置声明
class HighEndBouquet;
class EconomyBouquet;

// 花束工厂接口
class IBouquetFactory {
public:
    virtual IBouquet* createBouquet() = 0;
};

// 高端花束类
class HighEndBouquet : public IBouquet {
public:
    void deliver(std::string address) override;
};

// 经济型花束类
class EconomyBouquet : public IBouquet {
public:
    void deliver(std::string address) override;
};

// 高端花束工厂
class HighEndBouquetFactory : public IBouquetFactory {
public:
    IBouquet* createBouquet() override;
private:
    std::string Hf[2];
};

// 经济型花束工厂
class EconomyBouquetFactory : public IBouquetFactory {
public:
    IBouquet* createBouquet() override;
private:
    std::string Ef[2];
};



void Flowershop::deliver(std::string address) {
    cout << "The flower shop will deliver the bouquet to the address:" << address << endl;
}

DeliveryProxy::DeliveryProxy() {
    flowerShop = new Flowershop();
}

void DeliveryProxy::deliver(std::string address) {
    cout << "The agent receives the delivery request and will coordinate with an external courier company to complete the delivery task." << endl;
    flowerShop->deliver(address);
}

void HighEndBouquet::deliver(std::string address) {
    cout << "High-end bouquet will be delivered to the address:" << address << endl;
}

void EconomyBouquet::deliver(std::string address) {
    cout << "Economical bouquet will be delivered to the address: " << address << endl;
}

IBouquet* HighEndBouquetFactory::createBouquet() {
    cout << "Create a high-end bouquet.*********" << endl;
    // 实际创建高端花束的代码
    Hf[0] = "Freudian rose";
    Hf[1] = "Lan Dai";
    std::cout << Hf[0] << ' ' << Hf[1] << std::endl;
    return new HighEndBouquet();
}

IBouquet* EconomyBouquetFactory::createBouquet() {
    cout << "Create an economical bouquet.*********" << endl;
    // 实际创建经济型花束的代码
    Ef[0] = "coreopsis";
    Ef[1] = "sunflower";
    std::cout << Ef[0] << ' ' << Ef[1] << std::endl;
    return new EconomyBouquet();
}

void testProxy();
