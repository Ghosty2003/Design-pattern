#include<iostream>
#include"ChainOfResponsibility.h"


void FlowerArrangementHandler::handleOrder(
    Order& order, const string& message) {
    if (message == "FlowerArrangement") {
        order.request("花束制作完成");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void PackagingHandler::handleOrder(Order& order, const string& message) {
    if (message == "Packaging") {
        order.request("花束包装完成");
    }
    else {
        OrderHandler::handleOrder(order, message);
    }
}

void SalesHandler::handleOrder(Order& order, const string& message) {
    if (message == "Sales") {
        order.request("花束销售完成");
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

    // 构建责任链
    flowerArrangementHandler.setSuccessor(&packagingHandler);
    packagingHandler.setSuccessor(&salesHandler);

    // 发送订单请求
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