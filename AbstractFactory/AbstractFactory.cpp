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
    cout << "花店将把花束送到以下地址：" << address << endl;
}

DeliveryProxyRQX::DeliveryProxyRQX() {
    flowerShop = new FlowershopRQX();
}

void DeliveryProxyRQX::deliver(std::string address) {
    cout << "代理人收到快递请求后，将与外部快递公司协调完成快递任务。" << endl;
    flowerShop->deliver(address);
}

void HighEndBouquetRQX::deliver(std::string address) {
    cout << "高端花束将送到以下地址：" << address << endl;
}

void EconomyBouquetRQX::deliver(std::string address) {
    cout << "经济型花束将送到以下地址： " << address << endl;
}

IBouquetRQX* HighEndBouquetFactoryRQX::createBouquet() {
    cout << "创建高端花束*********" << endl;
    // 
    Hf[0] = "弗洛伊德玫瑰";
    Hf[1] = "兰黛";
    std::cout << Hf[0] << ' ' << Hf[1] << std::endl;
    return new HighEndBouquetRQX();
}

IBouquetRQX* EconomyBouquetFactoryRQX::createBouquet() {

    cout << "创建经济型花束*********" << endl;
    // 
    Ef[0] = "波斯菊";
    Ef[1] = "向日葵";

    std::cout << Ef[0] << ' ' << Ef[1] << std::endl;
    return new EconomyBouquetRQX();
}

void testAbstractFactory() {
    // 
    IBouquetRQX* deliveryProxy = new DeliveryProxyRQX();


    deliveryProxy->deliver("*曼彻斯特维多利亚街*");

    // 
    IBouquetFactoryRQX* highEndFactory = new HighEndBouquetFactoryRQX();
    IBouquetRQX* highEndBouquet = highEndFactory->createBouquet();

    highEndBouquet->deliver("*曼彻斯特 - 维多利亚街 - 维多利亚教堂*");

    IBouquetFactoryRQX* economyFactory = new EconomyBouquetFactoryRQX();
    IBouquetRQX* economyBouquet = economyFactory->createBouquet();
    economyBouquet->deliver("*曼彻斯特 - 维多利亚街 - 曼彻斯特大学*");


    delete deliveryProxy;
    delete highEndFactory;
    delete economyFactory;
    delete highEndBouquet;
    delete economyBouquet;

}


void testAbstractFactory();