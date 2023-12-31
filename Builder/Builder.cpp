#include "Builder.h"
#include <iostream>

void Order::setFlowerType(const std::string& type) { flowerType = type; }
void Order::setQuantity(int qty) { quantity = qty; }
void Order::setStatus(const std::string& status) { this->status = status; }
void Order::setOccasion(const std::string& oc) {
    occasion = oc;  // 假设您已经在类中声明了 'occasion' 成员变量
}

void Order::setPackagingMaterial(const std::string& mat) {
    packagingMaterial = mat;  // 假设您已经在类中声明了 'packagingMaterial' 成员变量
}

std::string Order::getInfo() {
    return "Flower: " + flowerType + ", Quantity: " + std::to_string(quantity) + ", Status: " + status;
}
std::string Order::getGift() {
    return "Occasion: " + occasion + ", Packaging Material: " + packagingMaterial;
}

std::shared_ptr<Order> OrderBuilder::getOrder() {
    return order;
}

void RoseOrderBuilder::buildFlowerType() { order->setFlowerType("玫瑰"); }
void RoseOrderBuilder::buildQuantity() { order->setQuantity(12); }
void RoseOrderBuilder::buildStatus() { order->setStatus("正在进行"); }
void RoseOrderBuilder::buildOccasion() {}
void RoseOrderBuilder::buildPackagingMaterial() {}

void LilyOrderBuilder::buildFlowerType() { order->setFlowerType("百合"); }
void LilyOrderBuilder::buildQuantity() { order->setQuantity(8); }
void LilyOrderBuilder::buildStatus() { order->setStatus("已经完成"); }
void LilyOrderBuilder::buildOccasion() {}
void LilyOrderBuilder::buildPackagingMaterial() {}


// BirthdayGiftBoxBuilder 的实现
void BirthdayOrderBuilder::buildFlowerType() { order->setFlowerType("玫瑰"); /*...*/ }
void BirthdayOrderBuilder::buildQuantity() {
    order->setQuantity(8); // 假设数量是8
}
void BirthdayOrderBuilder::buildStatus() {
    order->setStatus("进行中");
}
void BirthdayOrderBuilder::buildOccasion() { order->setOccasion("Birthday"); }
void BirthdayOrderBuilder::buildPackagingMaterial() { order->setPackagingMaterial("Colorful Paper"); }

// ValentineGiftBoxBuilder 的实现
void ValentineOrderBuilder::buildFlowerType() { order->setFlowerType("百合"); /*...*/ }
void ValentineOrderBuilder::buildQuantity() {
    order->setQuantity(10); // 假设数量是8
}
void ValentineOrderBuilder::buildStatus() {
    order->setStatus("已完成");
}
void ValentineOrderBuilder::buildOccasion() { order->setOccasion("Valentine's Day"); }
void ValentineOrderBuilder::buildPackagingMaterial() { order->setPackagingMaterial("Red Ribbon"); }


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
    builder->buildOccasion();
    builder->buildPackagingMaterial();
    return builder->getOrder();
}
void testBuilder() {
    // 创建生日礼盒订单
    Director director;
    director.setBuilder(new BirthdayOrderBuilder());
    std::shared_ptr<Order> birthdayOrder = director.construct();
    std::cout << "创建了一笔生日礼盒订单：" << std::endl;
    std::cout << birthdayOrder->getInfo() << std::endl;
    std::cout << "生日礼盒详情：" << std::endl;
    std::cout << birthdayOrder->getGift() << std::endl << std::endl;

    // 创建情人节礼盒订单
    director.setBuilder(new ValentineOrderBuilder());
    std::shared_ptr<Order> valentineOrder = director.construct();
    std::cout << "创建了一笔情人节礼盒订单：" << std::endl;
    std::cout << valentineOrder->getInfo() << std::endl;
    std::cout << "生日礼盒详情：" << std::endl;
    std::cout << birthdayOrder->getGift() << std::endl << std::endl;
    
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