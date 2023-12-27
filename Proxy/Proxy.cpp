#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "Proxy.h"

using namespace std;

void testProxy() {
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

/*
int main()
{
    testProxy();
}*/
