// FlowerShop.h

#pragma once

#include <iostream>
#include <vector>
#include <string>

// ö�����ͱ�ʾ��ͬ���͵���Ϣ
enum class FlowerShopMessageType {
    NewArrival,          // ��Ʒ�ϼ�
    EventAnnouncement,   // �����
    InventoryUpdate,     // ������
};

// ��ǰ���� FlowerShopSubscriber���Ա���ѭ������
class FlowerShopSubscriber;

// ���󷢲�����
class FlowerShopPublisher {
public:
    virtual void subscribe(FlowerShopSubscriber* subscriber) = 0;
    virtual void unsubscribe(FlowerShopSubscriber* subscriber) = 0;
    virtual void notifySubscribers(FlowerShopMessageType messageType, const std::string& message) = 0;
};

// ����������
class FlowerShopSubscriber {
public:
    virtual void update(FlowerShopMessageType messageType, const std::string& message) = 0;
};

// ���巢�����࣬��ʾ���ܿ�����ϵͳ
class InventoryManagementSystem : public FlowerShopPublisher {
private:
    std::vector<FlowerShopSubscriber*> subscribers;

public:
    // ���ķ���
    void subscribe(FlowerShopSubscriber* subscriber) override;

    // ȡ�����ķ����������Ҫ�Ļ�����ʵ��
    void unsubscribe(FlowerShopSubscriber* subscriber) override;

    // ֪ͨ�����ߵķ���
    void notifySubscribers(FlowerShopMessageType messageType, const std::string& message) override;

    // ģ�������
    void updateInventory(const std::string& flowerName, int quantity);
};

// ���嶩�����࣬��ʾ�˿�
class Customer : public FlowerShopSubscriber {
private:
    std::string name;

public:
    // ���캯��
    Customer(const std::string& name);

    // ���·����������յ�֪ͨʱ����
    void update(FlowerShopMessageType messageType, const std::string& message) override;

    // ���Ļ���֪ͨ�ķ���
    void subscribeToFlowerShop(FlowerShopPublisher* publisher);
};

// ���嶩�����࣬��ʾ����ϵͳ
class SalesSystem : public FlowerShopSubscriber {
public:
    // ���·����������յ�֪ͨʱ����
    void update(FlowerShopMessageType messageType, const std::string& message) override;

    // ���Ļ���֪ͨ�ķ���
    void subscribeToFlowerShop(FlowerShopPublisher* publisher);
};

// ��ͷ�ļ����������Ժ���
void testPublishSubscribe();