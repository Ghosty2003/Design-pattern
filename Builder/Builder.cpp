#include "Builder.h"
#include <iostream>

void Order::setFlowerType(const std::string& type) { flowerType = type; }
void Order::setQuantity(int qty) { quantity = qty; }
void Order::setStatus(const std::string& status) { this->status = status; }
void Order::setOccasion(const std::string& oc) {
    occasion = oc;  // �������Ѿ������������� 'occasion' ��Ա����
}

void Order::setPackagingMaterial(const std::string& mat) {
    packagingMaterial = mat;  // �������Ѿ������������� 'packagingMaterial' ��Ա����
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

void RoseOrderBuilder::buildFlowerType() { order->setFlowerType("õ��"); }
void RoseOrderBuilder::buildQuantity() { order->setQuantity(12); }
void RoseOrderBuilder::buildStatus() { order->setStatus("���ڽ���"); }
void RoseOrderBuilder::buildOccasion() {}
void RoseOrderBuilder::buildPackagingMaterial() {}

void LilyOrderBuilder::buildFlowerType() { order->setFlowerType("�ٺ�"); }
void LilyOrderBuilder::buildQuantity() { order->setQuantity(8); }
void LilyOrderBuilder::buildStatus() { order->setStatus("�Ѿ����"); }
void LilyOrderBuilder::buildOccasion() {}
void LilyOrderBuilder::buildPackagingMaterial() {}


// BirthdayGiftBoxBuilder ��ʵ��
void BirthdayOrderBuilder::buildFlowerType() { order->setFlowerType("õ��"); /*...*/ }
void BirthdayOrderBuilder::buildQuantity() {
    order->setQuantity(8); // ����������8
}
void BirthdayOrderBuilder::buildStatus() {
    order->setStatus("������");
}
void BirthdayOrderBuilder::buildOccasion() { order->setOccasion("Birthday"); }
void BirthdayOrderBuilder::buildPackagingMaterial() { order->setPackagingMaterial("Colorful Paper"); }

// ValentineGiftBoxBuilder ��ʵ��
void ValentineOrderBuilder::buildFlowerType() { order->setFlowerType("�ٺ�"); /*...*/ }
void ValentineOrderBuilder::buildQuantity() {
    order->setQuantity(10); // ����������8
}
void ValentineOrderBuilder::buildStatus() {
    order->setStatus("�����");
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
    // ����������ж���
    Director director;
    director.setBuilder(new BirthdayOrderBuilder());
    std::shared_ptr<Order> birthdayOrder = director.construct();
    std::cout << "������һ��������ж�����" << std::endl;
    std::cout << birthdayOrder->getInfo() << std::endl;
    std::cout << "����������飺" << std::endl;
    std::cout << birthdayOrder->getGift() << std::endl << std::endl;

    // �������˽���ж���
    director.setBuilder(new ValentineOrderBuilder());
    std::shared_ptr<Order> valentineOrder = director.construct();
    std::cout << "������һ�����˽���ж�����" << std::endl;
    std::cout << valentineOrder->getInfo() << std::endl;
    std::cout << "����������飺" << std::endl;
    std::cout << birthdayOrder->getGift() << std::endl << std::endl;
    
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