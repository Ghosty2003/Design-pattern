#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class FlowerShop_YH;
class Mediator_YH;
int shop_num = 0;

// 中介者抽象类
class Mediator_YH {
public:
    virtual void addFlower(const string& flower, FlowerShop_YH* shop) = 0;
    virtual void removeFlower(const string& flower, FlowerShop_YH* shop) = 0;
    virtual void sellFlower(const string& flower, FlowerShop_YH* shop) = 0;
};

// 同事类
class FlowerShop_YH {
public:
    vector<string> flowerList;
    Mediator_YH* mediator;
    int num;

    FlowerShop_YH(Mediator_YH* mediator) : mediator(mediator) { shop_num++; num = shop_num; }

    bool hasFlower(const string& flower) {
        vector<string>::iterator iter = find(flowerList.begin(), flowerList.end(), flower);
        return (iter != flowerList.end());
    }

    void addFlower(const string& flower);
    void removeFlower(const string& flower);
    void sellFlower(const string& flower);
    void showFlowerList();
};

// 具体中介者类
class ConcreteMediator_YH : public Mediator_YH {
public:
    vector<FlowerShop_YH*> shopList;

    virtual void addFlower(const string& flower, FlowerShop_YH* shop);
    virtual void removeFlower(const string& flower, FlowerShop_YH* shop);
    virtual void sellFlower(const string& flower, FlowerShop_YH* shop);
};

void FlowerShop_YH::addFlower(const string& flower) {
    flowerList.push_back(flower);
    cout << "Add " << flower << " to " << this->num << " flower shop." << endl;
    mediator->addFlower(flower, this);
}

void FlowerShop_YH::removeFlower(const string& flower) {
    vector<string>::iterator iter = find(flowerList.begin(), flowerList.end(), flower);
    if (iter != flowerList.end()) {
        flowerList.erase(iter);
        mediator->removeFlower(flower, this);
    }
}

void FlowerShop_YH::sellFlower(const string& flower) {
    vector<string>::iterator iter = find(flowerList.begin(), flowerList.end(), flower);
    if (iter != flowerList.end()) {
        cout << "Sell " << *iter << "." << endl;
        flowerList.erase(iter);
        mediator->sellFlower(flower, this);
    }
}


void FlowerShop_YH::showFlowerList() {
    cout << "Flower List:" << endl;
    for (vector<string>::iterator iter = flowerList.begin(); iter != flowerList.end(); ++iter) {
        cout << *iter << endl;
    }
    cout << endl;
}


void ConcreteMediator_YH::addFlower(const string& flower, FlowerShop_YH* shop) {
    for (vector<FlowerShop_YH*>::iterator iter = shopList.begin(); iter != shopList.end(); ++iter) {
        if (*iter != shop && !(*iter)->hasFlower(flower)) {
            (*iter)->addFlower(flower);
        }
    }

}

void ConcreteMediator_YH::removeFlower(const string& flower, FlowerShop_YH* shop) {
    for (vector<FlowerShop_YH*>::iterator iter = shopList.begin(); iter != shopList.end(); ++iter) {
        if (*iter != shop) {
            (*iter)->removeFlower(flower);
        }
    }
    cout << "Remove " << flower << " from all other flower shops." << endl;
}

void ConcreteMediator_YH::sellFlower(const string& flower, FlowerShop_YH* shop) {
    for (vector<FlowerShop_YH*>::iterator iter = shopList.begin(); iter != shopList.end(); ++iter) {
        if (*iter != shop) {
            (*iter)->removeFlower(flower);
        }
    }
    cout << "Sell " << flower << " from all flower shops." << endl;
}

void testMediator();//测试函数
