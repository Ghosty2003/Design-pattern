#include "Command.h"
#include <iostream>
#include <string>
#include <memory>
#include <windows.h>
using namespace std;

void testCommand() {
    // ����������
    OrderReceiver receiver;

    // ��������ʵ��
    FlowerShop shop;

    // ��������������õ�����
    auto order1 = std::make_shared<PlaceOrderCommand>(receiver, "Rose Bouquet");
    shop.setCommand(order1);

    // ִ������
    shop.submitOrder();
    Sleep(500);

    // �����ڶ�������
    auto order2 = std::make_shared<PlaceOrderCommand>(receiver, "Lily Bouquet");
    shop.setCommand(order2);

    // ִ������
    shop.submitOrder();
    Sleep(500);

    // ���������������ڶ������
    shop.undoOrder();
    Sleep(500);

    // �����Ҫ�������ٴγ����������һ�����
    shop.undoOrder();
    Sleep(500);
}
