#include "Command.h"
#include <iostream>
#include <string>
#include <memory>
#include <windows.h>
using namespace std;

void testCommand() {
    // 创建接收者
    OrderReceiver receiver;

    // 创建花店实例
    FlowerShop shop;

    // 创建命令并将其设置到花店
    auto order1 = std::make_shared<PlaceOrderCommand>(receiver, "Rose Bouquet");
    shop.setCommand(order1);

    // 执行命令
    shop.submitOrder();
    Sleep(500);

    // 创建第二个命令
    auto order2 = std::make_shared<PlaceOrderCommand>(receiver, "Lily Bouquet");
    shop.setCommand(order2);

    // 执行命令
    shop.submitOrder();
    Sleep(500);

    // 撤销最近的命令（即第二个命令）
    shop.undoOrder();
    Sleep(500);

    // 如果需要，可以再次撤销命令（即第一个命令）
    shop.undoOrder();
    Sleep(500);
}
