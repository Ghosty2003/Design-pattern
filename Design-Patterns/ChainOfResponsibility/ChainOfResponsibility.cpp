#include<iostream>
#include"ChainOfResponsibility.h"


void FlowerArrangementHandler::handleOrder(
    Order& order, const string& message) {
    if (message == "FlowerArrangement") {
        order.request("�����������");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void PackagingHandler::handleOrder(Order& order, const string& message) {
    if (message == "Packaging") {
        order.request("������װ���");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void SalesHandler::handleOrder(Order& order, const string& message) {
    if (message == "Sales") {
        order.request("�����������");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}



void testChainOfResponsibility() {
    Order order;
    FlowerArrangementHandler flowerArrangementHandler;
    PackagingHandler packagingHandler;
    SalesHandler salesHandler;

    // ����������
    flowerArrangementHandler.setSuccessor(&packagingHandler);
    packagingHandler.setSuccessor(&salesHandler);

    // ���Ͷ�������
    flowerArrangementHandler.handleOrder(order, "FlowerArrangement");
    flowerArrangementHandler.handleOrder(order, "Packaging");
    flowerArrangementHandler.handleOrder(order, "Sales");
}

//int main() {
//   
//    testChainOfResponsibility();
//
//	return 0;
//}