#include"Iterator.h"
void  testIterator() {
    srand(time(0));

    
    // 创建花店
    FlowerShopxlj2 flowerShop;
    flowerShop.addFlowerType("玫瑰");
    flowerShop.addFlowerType("郁金香");
    flowerShop.addFlowerType("百合");
    flowerShop.addFlowerType("康乃馨");
    flowerShop.addFlowerType("牡丹");
    flowerShop.addFlowerType("紫罗兰");
    flowerShop.addFlowerType("月季");
    flowerShop.addFlowerType("紫罗兰");
    flowerShop.addFlowerType("勿忘我");
    // 获取迭代器
    Iterator* iterator = flowerShop.createIterator();
    std::cout << "***************************************花店****************************************" << std::endl;
    
    int m = 1;
    // 遍历花店所有种类的鲜花
    while (iterator->hasNext()) {
        const std::string& flowerType = iterator->next();
        int color = rand() % 15 + 1;
        cct_setcolor(COLOR_BLACK, color);
        int n = 0;
        while (n != m) {
            n++;
            std::cout << "    ";
        }
            std::cout << flowerType << std::endl;
            m++;
    }
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        delete iterator; // 释放迭代器内存
    
}
