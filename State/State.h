#include <iostream>

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
        std::cout << "�������۸�������ʻ��ܡ�" << std::endl;
    }
};

// ����״̬�� - �е㲻���ʵĻ���
class SlightlyWitheredFlowerState : public FlowerState {
public:
    void process() override {
        std::cout << "���������ۿۼ��������в����ʵĻ��ܡ�" << std::endl;
    }
};

// ����״̬�� - ��ή��Ʒ�νϲ�Ļ���
class WitheredFlowerState : public FlowerState {
public:
    void process() override {
        std::cout << "������ή��Ʒ�νϲ�Ļ��ܡ�" << std::endl;
    }
};

// �������� - ����
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