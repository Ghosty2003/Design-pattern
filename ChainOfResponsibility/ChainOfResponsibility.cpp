#include<iostream>
#include"ChainOfResponsibility.h"


void FlowerArrangementHandler_wwj::handleOrder(
    Order_wwj& order, const string& message) {
    if (message == "FlowerArrangement") {
        order.request("�����������");
    }
    else {
        OrderHandler_wwj::handleOrder(order, message);
    }
}

void PackagingHandler_wwj::handleOrder(Order_wwj& order, const string& message) {
    if (message == "Packaging") {
        order.request("������װ���");
    }
    else {
        OrderHandler_wwj::handleOrder(order, message);
    }
}

void SalesHandler_wwj::handleOrder(Order_wwj& order, const string& message) {
    if (message == "Sales") {
        order.request("�����������");
    }
    else {
        OrderHandler_wwj::handleOrder(order, message);
    }
}



void testChainOfResponsibility() {
    Order_wwj order;
    FlowerArrangementHandler_wwj flowerArrangementHandler;
    PackagingHandler_wwj packagingHandler;
    SalesHandler_wwj salesHandler;

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