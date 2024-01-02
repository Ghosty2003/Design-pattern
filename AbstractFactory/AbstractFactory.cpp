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
    cout << "���꽫�ѻ����͵����µ�ַ��" << address << endl;
}

DeliveryProxyRQX::DeliveryProxyRQX() {
    flowerShop = new FlowershopRQX();
}

void DeliveryProxyRQX::deliver(std::string address) {
    cout << "�������յ��������󣬽����ⲿ��ݹ�˾Э����ɿ������" << endl;
    flowerShop->deliver(address);
}

void HighEndBouquetRQX::deliver(std::string address) {
    cout << "�߶˻������͵����µ�ַ��" << address << endl;
}

void EconomyBouquetRQX::deliver(std::string address) {
    cout << "�����ͻ������͵����µ�ַ�� " << address << endl;
}

IBouquetRQX* HighEndBouquetFactoryRQX::createBouquet() {
    cout << "�����߶˻���*********" << endl;
    // 
    Hf[0] = "��������õ��";
    Hf[1] = "����";
    std::cout << Hf[0] << ' ' << Hf[1] << std::endl;
    return new HighEndBouquetRQX();
}

IBouquetRQX* EconomyBouquetFactoryRQX::createBouquet() {

    cout << "���������ͻ���*********" << endl;
    // 
    Ef[0] = "��˹��";
    Ef[1] = "���տ�";

    std::cout << Ef[0] << ' ' << Ef[1] << std::endl;
    return new EconomyBouquetRQX();
}

void testAbstractFactory() {
    // 
    IBouquetRQX* deliveryProxy = new DeliveryProxyRQX();


    deliveryProxy->deliver("*����˹��ά�����ǽ�*");

    // 
    IBouquetFactoryRQX* highEndFactory = new HighEndBouquetFactoryRQX();
    IBouquetRQX* highEndBouquet = highEndFactory->createBouquet();

    highEndBouquet->deliver("*����˹�� - ά�����ǽ� - ά�����ǽ���*");

    IBouquetFactoryRQX* economyFactory = new EconomyBouquetFactoryRQX();
    IBouquetRQX* economyBouquet = economyFactory->createBouquet();
    economyBouquet->deliver("*����˹�� - ά�����ǽ� - ����˹�ش�ѧ*");


    delete deliveryProxy;
    delete highEndFactory;
    delete economyFactory;
    delete highEndBouquet;
    delete economyBouquet;

}


void testAbstractFactory();