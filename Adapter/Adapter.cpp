#include<iostream>
#include "Adapter.h"
using namespace std;

void testAdaptor()
{
    std::cout << "��ϵͳ�Ӳ�ͬ�Ļ��ܹ�Ӧ�̻�ȡ������Ϣ����ͨ�����������ģʽ������ͳһ����ͬ�Ľӿ�"
        << "���Ա��ڻ���ϵͳ�з���ش����չʾ��Щ������Ϣ��" << std::endl
        << std::endl;

    // ʹ�������������һ�����ܹ�Ӧ�̵����ݣ���̬���ü۸����������ơ���ɫ
    FlowerSupplier1 supplier1;
    double price1 = 20.0;  // ���û��ܼ۸�
    std::string name1 = "õ��";
    std::string description1 = "������1�ṩ";
    std::string color1 = "��ɫ";
    FlowerInfo* adapter1 = new FlowerSupplierAdapter1(supplier1, price1, name1, description1, color1);
    std::cout << "Flower Name: " << adapter1->getName() << ", Price: " << adapter1->getPrice()
        << ", Description: " << adapter1->getDescription() << ", Color: " << adapter1->getColor() << std::endl;

    // ʹ������������ڶ������ܹ�Ӧ�̵����ݣ���̬���ü۸����������ơ���ɫ
    FlowerSupplier2 supplier2;
    double price2 = 25.0;  // ���û��ܼ۸�
    std::string name2 = "�ٺ�";
    std::string description2 = "������2�ṩ";
    std::string color2 = "��ɫ";
    FlowerInfo* adapter2 = new FlowerSupplierAdapter2(supplier2, price2, name2, description2, color2);
    std::cout << "Flower Name: " << adapter2->getName() << ", Price: " << adapter2->getPrice()
        << ", Description: " << adapter2->getDescription() << ", Color: " << adapter2->getColor() << std::endl;

    delete adapter1;
    delete adapter2;
}



