#include "Compose.h"

class FlowerComponent;

void pressEntertoContinue() {
    std::cout << "按回车键继续...";
    std::cin.ignore();  // 忽略用户输入，等待回车
    std::cout << std::endl;
}

void flowerShopClientCode(FlowerComponent* component) {
    std::cout << "产品详情: " << component->Operation() << std::endl;
    pressEntertoContinue();
}

void testCompose() {
    FlowerComponent* product1 = new SingleFlower("玫瑰花束");
    FlowerComponent* product2 = new SingleFlower("康乃馨花瓶");

    FlowerComponent* set1 = new FlowerSet("情人节特别套装");
    set1->Add(product1);
    set1->Add(product2);

    FlowerComponent* product3 = new SingleFlower("郁金香花瓶");

    FlowerComponent* set2 = new FlowerSet("生日庆典套装");
    set2->Add(product3);

    flowerShopClientCode(product1);
    flowerShopClientCode(product2);
    flowerShopClientCode(set1);
    flowerShopClientCode(set2);

    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;
}
