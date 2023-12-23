#include<iostream>
#include "Adapter.h"
using namespace std;

void testAdaptor()
{
    std::cout << "该系统从不同的花卉供应商获取花卉信息，并通过适配器设计模式将它们统一成相同的接口"
        << "，以便在花店系统中方便地处理和展示这些花卉信息。" << std::endl
        << std::endl;

    // 使用适配器处理第一个花卉供应商的数据，动态设置价格、描述、名称、颜色
    FlowerSupplier1 supplier1;
    double price1 = 20.0;  // 设置花卉价格
    std::string name1 = "玫瑰";
    std::string description1 = "供货商1提供";
    std::string color1 = "红色";
    FlowerInfo* adapter1 = new FlowerSupplierAdapter1(supplier1, price1, name1, description1, color1);
    std::cout << "Flower Name: " << adapter1->getName() << ", Price: " << adapter1->getPrice()
        << ", Description: " << adapter1->getDescription() << ", Color: " << adapter1->getColor() << std::endl;

    // 使用适配器处理第二个花卉供应商的数据，动态设置价格、描述、名称、颜色
    FlowerSupplier2 supplier2;
    double price2 = 25.0;  // 设置花卉价格
    std::string name2 = "百合";
    std::string description2 = "供货商2提供";
    std::string color2 = "白色";
    FlowerInfo* adapter2 = new FlowerSupplierAdapter2(supplier2, price2, name2, description2, color2);
    std::cout << "Flower Name: " << adapter2->getName() << ", Price: " << adapter2->getPrice()
        << ", Description: " << adapter2->getDescription() << ", Color: " << adapter2->getColor() << std::endl;

    delete adapter1;
    delete adapter2;
}



