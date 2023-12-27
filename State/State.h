#include <iostream>

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
        std::cout << "以正常价格出售新鲜花卉。" << std::endl;
    }
};

// 具体状态类 - 有点不新鲜的花卉
class SlightlyWitheredFlowerState : public FlowerState {
public:
    void process() override {
        std::cout << "在晚上以折扣价销售略有不新鲜的花卉。" << std::endl;
    }
};

// 具体状态类 - 枯萎、品次较差的花卉
class WitheredFlowerState : public FlowerState {
public:
    void process() override {
        std::cout << "丢弃枯萎和品次较差的花卉。" << std::endl;
    }
};

// 上下文类 - 花店
class FlowerShop1 {
private:
    FlowerState* currentState;

public:
    FlowerShop1() : currentState(new FreshFlowerState()) {}

    void setState(FlowerState* state) {
        delete currentState;
        currentState = state;
    }

    void sellFlower() {
        currentState->process();
    }

    ~FlowerShop1() {
        delete currentState;
    }
};

void testState();