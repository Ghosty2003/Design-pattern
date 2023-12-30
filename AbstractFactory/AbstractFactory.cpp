#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "AbstractFactory.h"

using namespace std;
//此代码包含代理模式+抽象工厂模式，因为这两个模式相性较好，故做在一起
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

/*
int main()
{
    testAbstractFactory();
}*/
