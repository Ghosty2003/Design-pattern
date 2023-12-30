#include <iostream>
#include"../utils/cct_tools.h"
// 抽象状态类
class FlowerState {
public:
    virtual void process() = 0;
    virtual ~FlowerState() = default;
};

// 具体状态类 - 新鲜的花卉
class FreshFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_HRED);
        std::cout << "我们将以正常价格出售新鲜花卉" << std::endl;
    }
};

// 具体状态类 - 有点不新鲜的花卉
class SlightlyWitheredFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
        std::cout << "我们将以折扣价销售略有不新鲜的花卉" << std::endl;
    }
};

// 具体状态类 - 枯萎、品次较差的花卉
class WitheredFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_HBLACK);
        std::cout << "丢弃枯萎和品次较差的花卉" << std::endl;
    }
};

// 上下文类 - 花店
class FlowerShopxlj1 {
private:
    FlowerState* currentState;

public:
    FlowerShopxlj1() : currentState(new FreshFlowerState()) {}

    void setState(FlowerState* state) {
        delete currentState;
        currentState = state;
    }

    void sellFlower() {
        currentState->process();
    }

    ~FlowerShopxlj1() {
        delete currentState;
    }
};

void testState();