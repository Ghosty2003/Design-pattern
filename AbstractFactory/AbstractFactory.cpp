#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "AbstractFactory.h"

using namespace std;

void FlowerShop::deliver(std::string address) {
    cout << "花店将花束送到地址：" << address << endl;
}

DeliveryProxy::DeliveryProxy() {
    flowerShop = new FlowerShop();
}

void DeliveryProxy::deliver(std::string address) {
    cout << "代理收到送货请求，将协调外部快递公司来完成送货任务。" << endl;
    flowerShop->deliver(address);
}

void HighEndBouquet::deliver(std::string address) {
    cout << "高端花束将花束送到地址：" << address << endl;
}

void EconomyBouquet::deliver(std::string address) {
    cout << "经济型花束将花束送到地址：" << address << endl;
}

IBouquet* HighEndBouquetFactory::createBouquet() {
    cout << "创建高端花束。" << endl;
    // 实际创建高端花束的代码
    Hf[0] = "弗洛伊德玫瑰";
    Hf[1] = "岚黛";
    std::cout << Hf[0] << ' ' << Hf[1] << std::endl;
    return new HighEndBouquet();
}

IBouquet* EconomyBouquetFactory::createBouquet() {
    cout << "创建经济型花束。" << endl;
    // 实际创建经济型花束的代码
    Ef[0] = "波斯菊";
    Ef[1] = "向日葵";
    std::cout << Ef[0] << ' ' << Ef[1] << std::endl;
    return new EconomyBouquet();
}

void testAbstractFactory() {
    // 代理模式示例
    IBouquet* deliveryProxy = new DeliveryProxy();
    deliveryProxy->deliver("曼彻斯特-维多利亚街");

    // 抽象工厂模式示例
    IBouquetFactory* highEndFactory = new HighEndBouquetFactory();
    IBouquet* highEndBouquet = highEndFactory->createBouquet();
    highEndBouquet->deliver("曼彻斯特-维多利亚街-曼彻斯特大教堂");

    IBouquetFactory* economyFactory = new EconomyBouquetFactory();
    IBouquet* economyBouquet = economyFactory->createBouquet();
    economyBouquet->deliver("曼彻斯特-维多利亚街-曼彻斯特大学");

    delete deliveryProxy;
    delete highEndFactory;
    delete economyFactory;
    delete highEndBouquet;
    delete economyBouquet;

}


int main()
{
    testAbstractFactory();
}
