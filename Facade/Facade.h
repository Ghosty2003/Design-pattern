#pragma once
#include <iostream>

// ��ϵͳ1: ���ܿ�����
class InventorySystem {
public:
    void checkInventory();  // ��黨�ܿ��
    void updateInventory();  // ���»��ܿ��
};

// ��ϵͳ2: ��������
class OrderProcessingSystem {
public:
    void placeOrder();  // �µ�
    void processPayment();  // ����֧��
};

// ��ϵͳ3: �ͻ�����
class CustomerServiceSystem {
public:
    void provideAssistance();  // �ṩ�ͻ�����
};

// ��������ࣨFacade��
class FlowerShopFacade {
public:
    FlowerShopFacade();
    ~FlowerShopFacade();

    // �ͻ��Ѻõķ���
    void purchaseFlowers();  // ���򻨻�
    void arrangeEvent();  // ���Ż
    void deliverFlowers();  // �ͻ�����
    void assignRandomActivity(); //�������
};

void testFacade();