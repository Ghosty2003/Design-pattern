#include "Compose.h"
#include<sstream>
#include<string>

// 客户端代码，用于打印花卉组件的操作结果
void flowerShopClientCode(FlowerComponentGyy* component) {
    // 获取花卉组件的操作结果
    string output_ = component->Operation();

    // 解析操作结果并打印
    std::istringstream ss(output_);
    std::string token;
    cout << "*产品详情*：";
    static int count = 1;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE - (count++));
    while (std::getline(ss, token, ',')) {
        std::cout << token;
    }
}

// 示例方法，用于测试组合模式的功能
void testCompose() {
    // 创建单一花卉对象
    FlowerComponentGyy* product1 = new SingleFlower("*玫瑰花束*");
    FlowerComponentGyy* product2 = new SingleFlower("*康乃馨花束*");
    FlowerComponentGyy* product3 = new SingleFlower("*郁金香花束*");

    // 创建花束套装对象，并添加单一花卉对象
    FlowerComponentGyy* set1 = new FlowerSet("*情人节特别套装*");
    set1->Add(product1);
    set1->Add(product2);

    // 创建花束套装对象，并添加单一花卉对象和其他花束套装对象
    FlowerComponentGyy* set2 = new FlowerSet("*生日庆典套装*");
    set2->Add(product3);
    set2->Add(product3);  // 添加相同的单一花卉对象
    set2->Add(product1);

    // 设置控制台颜色，便于区分输出
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

    // 打印单一花卉和花束套装的操作结果
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

    // 恢复控制台颜色
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);

    // 释放动态分配的内存
    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;
}
