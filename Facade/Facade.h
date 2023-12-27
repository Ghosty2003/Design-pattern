#pragma once
#include <iostream>

// 子系统1: 花卉库存管理
class InventorySystem {
public:
    void checkInventory();  // 检查花卉库存
    void updateInventory();  // 更新花卉库存
};

// 子系统2: 订单处理
class OrderProcessingSystem {
public:
    void placeOrder();  // 下单
    void processPayment();  // 处理支付
};

// 子系统3: 客户服务
class CustomerServiceSystem {
public:
    void provideAssistance();  // 提供客户服务
};

// 花店外观类（Facade）
class FlowerShopFacade {
public:
    FlowerShopFacade();
    ~FlowerShopFacade();

    // 客户友好的方法
    void purchaseFlowers();  // 购买花卉
    void arrangeEvent();  // 安排活动
    void deliverFlowers();  // 送花服务
    void assignRandomActivity(); //随机分配活动
};

void testFacade();