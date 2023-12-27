#include"State.h"
void testState() {

    FlowerShop1 flowerShop;

    flowerShop.sellFlower();  // 初始状态，卖新鲜花

    flowerShop.setState(new SlightlyWitheredFlowerState());
    flowerShop.sellFlower();  // 晚上，卖有点不新鲜的花

    flowerShop.setState(new WitheredFlowerState());
    flowerShop.sellFlower();  // 卖枯萎的花，品次较差
}
