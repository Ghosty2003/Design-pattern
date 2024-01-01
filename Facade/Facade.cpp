#include "Facade.h"
#include <vector>

class InventorySystem;
class OrderProcessingSystem;
class CustomerServiceSystem;
class FlowerShopFacade;

// ʵ����ϵͳ1
void InventorySystem::checkInventory() {
    std::cout << "��黨�ܿ��..." << std::endl;
}

void InventorySystem::updateInventory() {
    std::cout << "���»��ܿ��..." << std::endl;
}

// ʵ����ϵͳ2
void OrderProcessingSystem::placeOrder() {
    std::cout << "�µ����򻨻�..." << std::endl;
}

void OrderProcessingSystem::processPayment() {
    std::cout << "������֧��..." << std::endl;
}

// ʵ����ϵͳ3
void CustomerServiceSystem::provideAssistance() {
    std::cout << "�ṩ�ͻ�����..." << std::endl;
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
}

// �������Ż�ķ���
void FlowerShopFacade::arrangeEvent() {
    std::cout << "��ӭ���ٻ��꣬Ϊ�˿Ͱ��Ż���װ�η���" << std::endl;
    std::cout << "����װ�ΰ�����ɣ�" << std::endl;
}

// �����ͻ�����ķ���
void FlowerShopFacade::deliverFlowers() {
    std::cout << "��ӭ���ٻ��꣬Ϊ�˿Ͱ����ͻ�����" << std::endl;
    std::cout << "�����ѳɹ��ʹ" << std::endl;
}

// ������������ķ���
void FlowerShopFacade::assignRandomActivity() {
    std::vector<void (FlowerShopFacade::*)()> activities = {
        &FlowerShopFacade::purchaseFlowers,
        &FlowerShopFacade::arrangeEvent,
        &FlowerShopFacade::deliverFlowers
    };


    // ���ѡ��һ���
    int randomIndex = rand() % 3;
    (this->*activities[randomIndex])();  // ����ѡ��Ļ
}

void testFacade() {

    srand((unsigned)time(0));

    FlowerShopFacade flowerShopGYYF;

    std::cout << "*~����Ϊ�˿�������仨��~*" << std::endl;

    for (int i = 1; i <= 3; i++) {
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        std::cout << "�� " << i << " ���˿���������" << std::endl;
        cct_setcolor(COLOR_BLACK, COLOR_HWHITE - i);
        flowerShopGYYF.assignRandomActivity();
        std::cout << std::endl;
    }

    cct_setcolor(COLOR_BLACK, COLOR_WHITE);

}
