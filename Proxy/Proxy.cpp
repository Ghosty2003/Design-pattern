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
    deliveryProxy->deliver("*Manchester Victoria Street*");

    // 抽象工厂模式示例
    IBouquetFactory* highEndFactory = new HighEndBouquetFactory();
    IBouquet* highEndBouquet = highEndFactory->createBouquet();
    highEndBouquet->deliver("*Manchester - Victoria Street - Manchester Cathedral*");

    IBouquetFactory* economyFactory = new EconomyBouquetFactory();
    IBouquet* economyBouquet = economyFactory->createBouquet();
    economyBouquet->deliver("*Manchester - Victoria Street - Manchester University*");

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
