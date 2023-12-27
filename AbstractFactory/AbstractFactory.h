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
class IBouquetRQX {
public:
    virtual void deliver(std::string address) = 0;
};

// 花店类
class FlowershopRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// 送货代理类
class DeliveryProxyRQX : public IBouquetRQX {
private:
    FlowershopRQX* flowerShop;
public:
    DeliveryProxyRQX();
    void deliver(std::string address) override;
};

// 抽象工厂模式

// 前置声明
class HighEndBouquetRQX;
class EconomyBouquetRQX;

// 花束工厂接口
class IBouquetFactoryRQX {
public:
    virtual IBouquetRQX* createBouquet() = 0;
};

// 高端花束类
class HighEndBouquetRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// 经济型花束类
class EconomyBouquetRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// 高端花束工厂
class HighEndBouquetFactoryRQX : public IBouquetFactoryRQX {
public:
    IBouquetRQX* createBouquet() override;
private:
    std::string Hf[2];
};

// 经济型花束工厂
class EconomyBouquetFactoryRQX : public IBouquetFactoryRQX {
public:
    IBouquetRQX* createBouquet() override;
private:
    std::string Ef[2];
};



void FlowershopRQX::deliver(std::string address) {
    cout << "The flower shop will deliver the bouquet to the address:" << address << endl;
}

DeliveryProxyRQX::DeliveryProxyRQX() {
    flowerShop = new FlowershopRQX();
}

void DeliveryProxyRQX::deliver(std::string address) {
    cout << "The agent receives the delivery request and will coordinate with an external courier company to complete the delivery task." << endl;
    flowerShop->deliver(address);
}

void HighEndBouquetRQX::deliver(std::string address) {
    cout << "High-end bouquet will be delivered to the address:" << address << endl;
}

void EconomyBouquetRQX::deliver(std::string address) {
    cout << "Economical bouquet will be delivered to the address: " << address << endl;
}

IBouquetRQX* HighEndBouquetFactoryRQX::createBouquet() {
    cout << "Create a high-end bouquet.*********" << endl;
    // 实际创建高端花束的代码
    Hf[0] = "Freudian rose";
    Hf[1] = "Lan Dai";
    std::cout << Hf[0] << ' ' << Hf[1] << std::endl;
    return new HighEndBouquetRQX();
}

IBouquetRQX* EconomyBouquetFactoryRQX::createBouquet() {
    cout << "Create an economical bouquet.*********" << endl;
    // 实际创建经济型花束的代码
    Ef[0] = "coreopsis";
    Ef[1] = "sunflower";
    std::cout << Ef[0] << ' ' << Ef[1] << std::endl;
    return new EconomyBouquetRQX();
}

void testAbstractFactory();
