#include "Compose.h"
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>

class FlowerComponent;

void flowerShopClientCode(FlowerComponent* component) {
    string output_ = component->Operation();

    std::istringstream ss(output_);
    std::string token;
    cout << "*产品详情*：";
    static int count = 1;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE-(count++));
    while (std::getline(ss,token,',')) {

        std::cout << token;
    }
    if (count == 15)
        count = 0;
}

FlowerComponent* chooseFlowerBouquet() {
    // 提供花束选项
    std::cout << "可以自由组合您的套装(输入0退出)：" << std::endl;
    std::cout << "1. 玫瑰花束  2. 康乃馨花束  3. 郁金香花束" << std::endl;
    std::cout << "按回车结束组合：" ;

    std::string userInput;
    std::getline(std::cin, userInput);

    if (userInput == "0") {
        return nullptr; // 用户选择退出，返回空指针
    }

    FlowerSet* userBouquet = new FlowerSet("*用户定制套装*");

    for (char c : userInput) {
        switch (c) {
        case '1':
            userBouquet->Add(new SingleFlower("*玫瑰花束*"));
            break;
        case '2':
            userBouquet->Add(new SingleFlower("*康乃馨花束*"));
            break;
        case '3':
            userBouquet->Add(new SingleFlower("*郁金香花束*"));
            break;
        default:
            std::cerr << "无效选项：" << c << std::endl;
            delete userBouquet;
            return nullptr; // 用户输入无效选项，返回空指针
        }
    }

    return userBouquet;
}



void testCompose() {
    FlowerComponent* product1 = new SingleFlower("*玫瑰花束*");
    FlowerComponent* product2 = new SingleFlower("*康乃馨花束*");
    FlowerComponent* product3 = new SingleFlower("*郁金香花束*");
    FlowerComponent* set1 = new FlowerSet("*情人节特别套装*");
    set1->Add(product1);
    set1->Add(product2);
    FlowerComponent* set2 = new FlowerSet("*生日庆典套装*");
    set2->Add(product3);
    set2->Add(product3);
    set2->Add(product1);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    flowerShopClientCode(product1);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(product2);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(set1);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(set2);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;

    // 选择用户花束
    while (1) {
        FlowerComponent* userBouquet = chooseFlowerBouquet();
        if (userBouquet == nullptr)
            break;
        if (userBouquet) {
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
            flowerShopClientCode(userBouquet);
            cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
            std::cout << std::endl;
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            delete userBouquet;
        }
    }
}
