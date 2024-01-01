#include "PublishSubscribe.h"

// FlowerShop.cpp



// 实现 InventoryManagementSystem 的成员函数

void InventoryManagementSystem::subscribe(FlowerShopSubscriber* subscriber) {
    subscribers.push_back(subscriber);
}

void InventoryManagementSystem::unsubscribe(FlowerShopSubscriber* subscriber) {
    // 实现取消订阅的逻辑
}

void InventoryManagementSystem::notifySubscribers(FlowerShopMessageType messageType, const std::string& message) {
    for (auto subscriber : subscribers) {
        subscriber->update(messageType, message);
    }
}

void InventoryManagementSystem::updateInventory(const std::string& flowerName, int quantity) {
    // 模拟库存更新逻辑
    // ...

    // 通知订阅者
    notifySubscribers(FlowerShopMessageType::InventoryUpdate, "Inventory updated: " + flowerName + " - Quantity: " + std::to_string(quantity));
}

// 实现 Customer 的成员函数

Customer::Customer(const std::string& name) : name(name) {}

void Customer::update(FlowerShopMessageType messageType, const std::string& message) {
    std::cout << "Customer " << name << " received a notification: " << message << std::endl;
}

void Customer::subscribeToFlowerShop(FlowerShopPublisher* publisher) {
    publisher->subscribe(this);
}

// 实现 SalesSystem 的成员函数

void SalesSystem::update(FlowerShopMessageType messageType, const std::string& message) {
    std::cout << "SalesSystem received a notification: " << message << std::endl;
}

void SalesSystem::subscribeToFlowerShop(FlowerShopPublisher* publisher) {
    publisher->subscribe(this);
}

// 测试函数

void testPublishSubscribe() {
    // 创建花店组件的实例
    InventoryManagementSystem inventorySystem;
    Customer customer1("Alice");
    Customer customer2("Bob");
    SalesSystem salesSystem;

    // 顾客订阅花店更新
    customer1.subscribeToFlowerShop(&inventorySystem);
    customer2.subscribeToFlowerShop(&inventorySystem);
    salesSystem.subscribeToFlowerShop(&inventorySystem);

    // 模拟库存更新
    inventorySystem.updateInventory("Roses", 50);
}

