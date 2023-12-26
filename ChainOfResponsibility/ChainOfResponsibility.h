#pragma once
#include<iostream>
using namespace std;

class Order {
public:
    void request(const string& message) {
        cout << "Order: " << message << endl;
    }
};


class OrderHandler {
protected:
    OrderHandler* successor;

public:
    OrderHandler() : successor(nullptr) {}

    void setSuccessor(OrderHandler* successor) {
        this->successor = successor;
    }

    virtual void handleOrder(Order& order, const string& message) {
        if (successor != nullptr) {
            successor->handleOrder(order, message);
        }
    }
};


class FlowerArrangementHandler : public OrderHandler {
public:
    void handleOrder(Order& order, const string& message);
};


class PackagingHandler : public OrderHandler {
public:
    void handleOrder(Order& order, const string& message);
};

class SalesHandler : public OrderHandler {
public:
    void handleOrder(Order& order, const string& message);
};

void testChainOfResponsibility();
