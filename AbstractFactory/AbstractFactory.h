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

// 花店�??
class FlowershopRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// 送货代理�??
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

// 高端花束�??
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

// 经济型花束工�??
class EconomyBouquetFactoryRQX : public IBouquetFactoryRQX {
public:
    IBouquetRQX* createBouquet() override;
private:
    std::string Ef[2];
};

void testAbstractFactory();
