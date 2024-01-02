#include"Iterator.h"
#include "../utils/cct_tools.h"
void  testIterator() {
    cct_cls();
    const char* sign[] = {
            "***************************************************************************************************",
            "*____   ____.__                __________                     .__                                 *",
            "*\\   \\ /   /|__| ______  _  __ \\______   \\__ _________   ____ |  |__ _____    ______ ____   ______*",
            "* \\   Y   / |  |/ __ \\ \\/ \\/ /  |     ___/  |  \\_  __ \\_/ ___\\|  |  \\\\__  \\  /  ___// __ \\ /  ___/*",
            "*  \\     /  |  \\  ___/\\     /   |    |   |  |  /|  | \\/\\  \\___|   Y  \\/ __ \\_\\___ \\\\  ___/ \\____\\ *",
            "*   \\___/   |__|\\_____>\\/\\_/    |____|   |____/ |__|    \\_____>___|  (______/______>\\_____>______>*",
            "*                                                                                                 *",
            "***************************************************************************************************"
    };

    for(int i = 0; i < 8; i++) {
        if (i == 0) {
            cct_setcolor(COLOR_BLACK, COLOR_PINK);
        }
        else if (i == 7) {
            cct_setcolor(COLOR_BLACK, COLOR_PINK);
        }
        else {
            cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
        }

        std::cout << sign[i] << std::endl;
    }
    cct_setcolor();
    cout << "下面是用户查看购买阶段：" << endl;
    system("pause");
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
    flowerShop.addFlowerType("仙人掌");
    flowerShop.addFlowerType("勿忘我");
    flowerShop.addFlowerType("富贵竹");
    flowerShop.addFlowerType("满天星");
    flowerShop.addFlowerType("剑兰");
    flowerShop.addFlowerType("桔梗花");
    flowerShop.addFlowerType("马蹄莲");
    flowerShop.addFlowerType("非洲菊");
    flowerShop.addFlowerType("向日葵");
    flowerShop.addFlowerType("情人草");
    flowerShop.addFlowerType("菊花");
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
