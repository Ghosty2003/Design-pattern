#pragma once
#include<iostream>
using namespace std;

class Order_wwj {
public:
    void request(const string& message) {
        cout << "Order: " << message << endl;
    }
};


class OrderHandler_wwj {
protected:
    OrderHandler_wwj* successor;

public:
    OrderHandler_wwj() : successor(nullptr) {}

    void setSuccessor(OrderHandler_wwj* successor) {
        this->successor = successor;
    }

    virtual void handleOrder(Order_wwj& order, const string& message) {
        if (successor != nullptr) {
            successor->handleOrder(order, message);
        }
    }
};


class FlowerArrangementHandler_wwj : public OrderHandler_wwj {
public:
    void handleOrder(Order_wwj& order, const string& message);
};


class PackagingHandler_wwj : public OrderHandler_wwj {
public:
    void handleOrder(Order_wwj& order, const string& message);
};

class SalesHandler_wwj : public OrderHandler_wwj {
public:
    void handleOrder(Order_wwj& order, const string& message);
};

void testChainOfResponsibility();
