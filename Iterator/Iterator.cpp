#include"Iterator.h"

void  testIterator() {
    // 创建花店
    FlowerShop2 flowerShop;
    flowerShop.addFlowerType("玫瑰");
    flowerShop.addFlowerType("郁金香");
    flowerShop.addFlowerType("百合");
    flowerShop.addFlowerType("康乃馨");

    // 获取迭代器
    Iterator* iterator = flowerShop.createIterator();

    // 遍历花店所有种类的鲜花
    while (iterator->hasNext()) {
        const std::string& flowerType = iterator->next();
        std::cout << "花店有：" << flowerType << std::endl;
    }

    delete iterator; // 释放迭代器内存
}
