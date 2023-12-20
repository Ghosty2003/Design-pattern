#include "Builder.h"
#include <iostream>

void Order::setFlowerType(const std::string& type) { flowerType = type; }
void Order::setQuantity(int qty) { quantity = qty; }
void Order::setStatus(const std::string& status) { this->status = status; }
std::string Order::getInfo() {
    return "Flower: " + flowerType + ", Quantity: " + std::to_string(quantity) + ", Status: " + status;
}

std::shared_ptr<Order> OrderBuilder::getOrder() {
    return order;
}

void RoseOrderBuilder::buildFlowerType() { order->setFlowerType("õ��"); }
void RoseOrderBuilder::buildQuantity() { order->setQuantity(12); }
void RoseOrderBuilder::buildStatus() { order->setStatus("���ڽ���"); }

void LilyOrderBuilder::buildFlowerType() { order->setFlowerType("�ٺ�"); }
void LilyOrderBuilder::buildQuantity() { order->setQuantity(8); }
void LilyOrderBuilder::buildStatus() { order->setStatus("�Ѿ����"); }

Director::~Director() {
    if (builder) {
        delete builder;
    }
}

void Director::setBuilder(OrderBuilder* b) {
    if (builder) {
        delete builder;
    }
    builder = b;
}

std::shared_ptr<Order> Director::construct() {
    builder->buildFlowerType();
    builder->buildQuantity();
    builder->buildStatus();
    return builder->getOrder();
}
void testBuilder() {
    Director director;

    // õ�廨����
    director.setBuilder(new RoseOrderBuilder());
    director.construct();
    std::shared_ptr<Order> roseOrder = director.construct();
    std::cout << "������һ��õ�廨������" << std::endl;
    std::cout << roseOrder->getInfo() << std::endl << std::endl;

    // �ٺϻ�����
    director.setBuilder(new LilyOrderBuilder());
    director.construct();
    std::shared_ptr<Order> lilyOrder = director.construct();
    std::cout << "������һ�ʰٺϻ�������" << std::endl;
    std::cout << lilyOrder->getInfo() << std::endl << std::endl;

}