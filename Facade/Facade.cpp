#include "Facade.h"
#include <vector>

class InventorySystem;
class OrderProcessingSystem;
class CustomerServiceSystem;
class FlowerShopFacade;

void pressEnterToContinue() {
    std::cout << "���س�������...";
    std::cin.ignore();  // �����û����룬�ȴ��س�
    std::cout << std::endl;
}

// ʵ����ϵͳ1
void InventorySystem::checkInventory() {
    std::cout << "��黨�ܿ��..." << std::endl;
    pressEnterToContinue();
}

void InventorySystem::updateInventory() {
    std::cout << "���»��ܿ��..." << std::endl;
    pressEnterToContinue();
}

// ʵ����ϵͳ2
void OrderProcessingSystem::placeOrder() {
    std::cout << "�µ����򻨻�..." << std::endl;
    pressEnterToContinue();
}

void OrderProcessingSystem::processPayment() {
    std::cout << "������֧��..." << std::endl;
    pressEnterToContinue();
}

// ʵ����ϵͳ3
void CustomerServiceSystem::provideAssistance() {
    std::cout << "�ṩ�ͻ�����..." << std::endl;
    pressEnterToContinue();
}

// ʵ�ֻ�������ࣨFacade��
FlowerShopFacade::FlowerShopFacade() {
    // ��ʼ����ϵͳ
}

FlowerShopFacade::~FlowerShopFacade() {
    // ������ϵͳ
}

// ʵ�ֹ��򻨻ܵķ���
void FlowerShopFacade::purchaseFlowers() {
    std::cout << "��ӭ���ٻ��꣡" << std::endl;
    InventorySystem().checkInventory();
    OrderProcessingSystem().placeOrder();
    OrderProcessingSystem().processPayment();
    CustomerServiceSystem().provideAssistance();
    std::cout << "��л���������ǵĵ��̣�" << std::endl;
    pressEnterToContinue();
}

// �������Ż�ķ���
void FlowerShopFacade::arrangeEvent() {
    std::cout << "��ӭ�����������ŷ���" << std::endl;
    std::cout << "�������ɣ�" << std::endl;
    pressEnterToContinue();
}

// �����ͻ�����ķ���
void FlowerShopFacade::deliverFlowers() {
    std::cout << "��ӭ���������ͻ�����" << std::endl;
    std::cout << "�����ѳɹ��ʹ" << std::endl;
    pressEnterToContinue();
}

// ������������ķ���
void FlowerShopFacade::assignRandomActivity() {
    std::vector<void (FlowerShopFacade::*)()> activities = {
        &FlowerShopFacade::purchaseFlowers,
        &FlowerShopFacade::arrangeEvent,
        &FlowerShopFacade::deliverFlowers
    };

    // ���ѡ��һ���
    int randomIndex = rand() % activities.size();
    (this->*activities[randomIndex])();  // ����ѡ��Ļ
}

void testFacade() {
    srand((unsigned)time(0));

    FlowerShopFacade flowerShopGYYF;

    for (int i = 1; i <= 3; i++) {
        std::cout << "�� " << i << " ���˿���������" << std::endl;
        flowerShopGYYF.assignRandomActivity();
        std::cout << std::endl;
        pressEnterToContinue();
    }
}

