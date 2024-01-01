#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "AbstractFactory.h"

using namespace std;

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

void testAbstractFactory() {
    // 代理模式示例
    IBouquetRQX* deliveryProxy = new DeliveryProxyRQX();
    deliveryProxy->deliver("*Manchester Victoria Street*");

    // 抽象工厂模式示例
    IBouquetFactoryRQX* highEndFactory = new HighEndBouquetFactoryRQX();
    IBouquetRQX* highEndBouquet = highEndFactory->createBouquet();
    highEndBouquet->deliver("*Manchester - Victoria Street - Manchester Cathedral*");

    IBouquetFactoryRQX* economyFactory = new EconomyBouquetFactoryRQX();
    IBouquetRQX* economyBouquet = economyFactory->createBouquet();
    economyBouquet->deliver("*Manchester - Victoria Street - Manchester University*");

    delete deliveryProxy;
    delete highEndFactory;
    delete economyFactory;
    delete highEndBouquet;
    delete economyBouquet;

}


void testAbstractFactory();

