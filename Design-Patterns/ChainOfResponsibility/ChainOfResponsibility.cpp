#include<iostream>
#include"ChainOfResponsibility.h"


void PaymentHandler::handleOrder(Order& order, const string& message) {
    if (message == "Payment") {
        order.request("֧������ɹ�");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void InventoryHandler::handleOrder(Order& order, const string& message) {
    if (message == "Inventory") {
        order.request("����⴦��ɹ�");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void testChainOfResponsibility() {
    Order order;
    PaymentHandler paymentHandler;
    InventoryHandler inventoryHandler;

    // ����������
    paymentHandler.setSuccessor(&inventoryHandler);

    // ���Ͷ�������
    paymentHandler.handleOrder(order, "Payment");
    paymentHandler.handleOrder(order, "Inventory");
    paymentHandler.handleOrder(order, "Shipping");
}

int main() {
   
    testChainOfResponsibility();

	return 0;
}