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

void RoseOrderBuilder::buildFlowerType() { order->setFlowerType("玫瑰"); }
void RoseOrderBuilder::buildQuantity() { order->setQuantity(12); }
void RoseOrderBuilder::buildStatus() { order->setStatus("正在进行"); }

void LilyOrderBuilder::buildFlowerType() { order->setFlowerType("百合"); }
void LilyOrderBuilder::buildQuantity() { order->setQuantity(8); }
void LilyOrderBuilder::buildStatus() { order->setStatus("已经完成"); }

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

    // 玫瑰花订单
    director.setBuilder(new RoseOrderBuilder());
    director.construct();
    std::shared_ptr<Order> roseOrder = director.construct();
    std::cout << "创建了一笔玫瑰花订单：" << std::endl;
    std::cout << roseOrder->getInfo() << std::endl << std::endl;

    // 百合花订单
    director.setBuilder(new LilyOrderBuilder());
    director.construct();
    std::shared_ptr<Order> lilyOrder = director.construct();
    std::cout << "创建了一笔百合花订单：" << std::endl;
    std::cout << lilyOrder->getInfo() << std::endl << std::endl;

}