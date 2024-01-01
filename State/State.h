#include <iostream>
#include"../utils/cct_tools.h"
// ����״̬��
class FlowerState {
public:
    virtual void process() = 0;
    virtual ~FlowerState() = default;
};

// ����״̬�� - ���ʵĻ���
class FreshFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_HRED);
        std::cout << "���ǽ��������۸�������ʻ���" << std::endl;
    }
};

// ����״̬�� - �е㲻���ʵĻ���
class SlightlyWitheredFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
        std::cout << "���ǽ����ۿۼ��������в����ʵĻ���" << std::endl;
    }
};

// ����״̬�� - ��ή��Ʒ�νϲ�Ļ���
class WitheredFlowerState : public FlowerState {
public:
    void process() override {
        cct_setcolor(COLOR_BLACK, COLOR_HBLACK);
        std::cout << "������ή��Ʒ�νϲ�Ļ���" << std::endl;
    }
};

// �������� - ����
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