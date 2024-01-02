// FlowerShop.h

#pragma once

#include <iostream>
#include <vector>
#include <string>

// 枚举类型表示不同类型的消息
enum class FlowerShopMessageType {
    NewArrival,          // 新品上架
    EventAnnouncement,   // 活动公告
    InventoryUpdate,     // 库存更新
};

// 提前声明 FlowerShopSubscriber，以避免循环依赖
class FlowerShopSubscriber;

// 抽象发布者类
class FlowerShopPublisher {
public:
    virtual void subscribe(FlowerShopSubscriber* subscriber) = 0;
    virtual void unsubscribe(FlowerShopSubscriber* subscriber) = 0;
    virtual void notifySubscribers(FlowerShopMessageType messageType, const std::string& message) = 0;
};

// 抽象订阅者类
class FlowerShopSubscriber {
public:
    virtual void update(FlowerShopMessageType messageType, const std::string& message) = 0;
};

// 具体发布者类，表示花卉库存管理系统
class InventoryManagementSystem : public FlowerShopPublisher {
private:
    std::vector<FlowerShopSubscriber*> subscribers;

public:
    // 订阅方法
    void subscribe(FlowerShopSubscriber* subscriber) override;

    // 取消订阅方法，如果需要的话可以实现
    void unsubscribe(FlowerShopSubscriber* subscriber) override;

    // 通知订阅者的方法
    void notifySubscribers(FlowerShopMessageType messageType, const std::string& message) override;

    // 模拟库存更新
    void updateInventory(const std::string& flowerName, int quantity);
};

// 具体订阅者类，表示顾客
class Customer : public FlowerShopSubscriber {
private:
    std::string name;

public:
    // 构造函数
    Customer(const std::string& name);

    // 更新方法，当接收到通知时调用
    void update(FlowerShopMessageType messageType, const std::string& message) override;

    // 订阅花店通知的方法
    void subscribeToFlowerShop(FlowerShopPublisher* publisher);
};

// 具体订阅者类，表示销售系统
class SalesSystem : public FlowerShopSubscriber {
public:
    // 更新方法，当接收到通知时调用
    void update(FlowerShopMessageType messageType, const std::string& message) override;

    // 订阅花店通知的方法
    void subscribeToFlowerShop(FlowerShopPublisher* publisher);
};

// 在头文件中声明测试函数
void testPublishSubscribe();