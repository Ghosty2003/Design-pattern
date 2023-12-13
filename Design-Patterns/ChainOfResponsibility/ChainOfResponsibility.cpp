#include<iostream>
#include"ChainOfResponsibility.h"


void PaymentHandler::handleOrder(Order& order, const string& message) {
    if (message == "Payment") {
        order.request("支付处理成功");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void InventoryHandler::handleOrder(Order& order, const string& message) {
    if (message == "Inventory") {
        order.request("库存检测处理成功");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void testChainOfResponsibility() {
    Order order;
    PaymentHandler paymentHandler;
    InventoryHandler inventoryHandler;

    // 构建责任链
    paymentHandler.setSuccessor(&inventoryHandler);

    // 发送订单请求
    paymentHandler.handleOrder(order, "Payment");
    paymentHandler.handleOrder(order, "Inventory");
    paymentHandler.handleOrder(order, "Shipping");
}

int main() {
   
    testChainOfResponsibility();

	return 0;
}