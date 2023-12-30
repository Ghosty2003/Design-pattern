#include "Compose.h"
#include<sstream>
#include<string>

class FlowerComponent;

void flowerShopClientCode(FlowerComponent* component) {
    string output_ = component->Operation();

    std::istringstream ss(output_);
    std::string token;
    cout << "*产品详情*：";
    static int count = 1;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE - (count++));
    while (std::getline(ss, token, ',')) {

        std::cout << token;
    }
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
}
