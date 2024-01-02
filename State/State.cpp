#include"State.h"
#include "../utils/cct_tools.h"
using namespace std;
void drawFreshFlower() {
    std::cout << "   @" << std::endl;
    std::cout << "  @@" << std::endl;
    std::cout << " @@@@" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "  |||" << std::endl;
    std::cout << std::endl;
    cct_setcolor();
}

void drawWitheredFlower() {
    
    std::cout << "  @" << std::endl;
    std::cout << " @@@" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "   X" << std::endl;
    std::cout << std::endl;
    cct_setcolor();
}
void testState() {
    FlowerShopxlj1 flowerShop;

    //cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    //std::cout << "对于不同新鲜状态的花卉，执行不同的处理方式\n" << endl;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << "欢迎光临State模式\n" << endl;

    system("pause");
    cct_setcolor(COLOR_BLACK, COLOR_HRED);
    
    cout << "清晨花店采购了一株新鲜花卉：" << endl;
    drawFreshFlower();
    flowerShop.sellFlower();  // 初始状态，卖新鲜花
    system("pause");
    std::cout << endl;


    
    cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
    std::cout << "傍晚这株花仍然没有销售出去" << endl;
    flowerShop.setState(new SlightlyWitheredFlowerState());
    flowerShop.sellFlower();  // 晚上，卖有点不新鲜的花
    system("pause");
    std::cout << endl;

    
    cct_setcolor(COLOR_BLACK, COLOR_HBLACK);
    std::cout << "花瓣逐渐凋零，看来这株花已经不被人需要" << endl;
    drawWitheredFlower();
    flowerShop.setState(new WitheredFlowerState());
    flowerShop.sellFlower();  // 卖枯萎的花，品次较差
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
