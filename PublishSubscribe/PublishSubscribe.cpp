#include "PublishSubscribe.h"

// FlowerShop.cpp



// ʵ�� InventoryManagementSystem �ĳ�Ա����

void InventoryManagementSystem::subscribe(FlowerShopSubscriber* subscriber) {
    subscribers.push_back(subscriber);
}

void InventoryManagementSystem::unsubscribe(FlowerShopSubscriber* subscriber) {
    // ʵ��ȡ�����ĵ��߼�
}

void InventoryManagementSystem::notifySubscribers(FlowerShopMessageType messageType, const std::string& message) {
    for (auto subscriber : subscribers) {
        subscriber->update(messageType, message);
    }
}

void InventoryManagementSystem::updateInventory(const std::string& flowerName, int quantity) {
    // ģ��������߼�
    // ...

    // ֪ͨ������
    notifySubscribers(FlowerShopMessageType::InventoryUpdate, "Inventory updated: " + flowerName + " - Quantity: " + std::to_string(quantity));
}

// ʵ�� Customer �ĳ�Ա����

Customer::Customer(const std::string& name) : name(name) {}

void Customer::update(FlowerShopMessageType messageType, const std::string& message) {
    std::cout << "Customer " << name << " received a notification: " << message << std::endl;
}

void Customer::subscribeToFlowerShop(FlowerShopPublisher* publisher) {
    publisher->subscribe(this);
}

// ʵ�� SalesSystem �ĳ�Ա����

void SalesSystem::update(FlowerShopMessageType messageType, const std::string& message) {
    std::cout << "SalesSystem received a notification: " << message << std::endl;
}

void SalesSystem::subscribeToFlowerShop(FlowerShopPublisher* publisher) {
    publisher->subscribe(this);
}

// ���Ժ���

void testPublishSubscribe() {
    // �������������ʵ��
    InventoryManagementSystem inventorySystem;
    Customer customer1("Alice");
    Customer customer2("Bob");
    SalesSystem salesSystem;

    // �˿Ͷ��Ļ������
    customer1.subscribeToFlowerShop(&inventorySystem);
    customer2.subscribeToFlowerShop(&inventorySystem);
    salesSystem.subscribeToFlowerShop(&inventorySystem);

    // ģ�������
    inventorySystem.updateInventory("Roses", 50);
}
