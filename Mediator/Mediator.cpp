#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Mediator.h"

using namespace std;

// ²âÊÔº¯Êý
void testMediator() {
    ConcreteMediator_YH* mediator = new ConcreteMediator_YH();

    FlowerShop_YH* shop1 = new FlowerShop_YH(mediator);

    mediator->shopList.push_back(shop1);


    FlowerShop_YH* shop2 = new FlowerShop_YH(mediator);
    mediator->shopList.push_back(shop2);

    cout << "Test add rose to shop1, shop2 will have rose too." << endl;
    shop1->addFlower("Rose");
    cout << endl;
    cout << "Test add carnation to shop2, shop1 will have carnation too." << endl;
    shop2->addFlower("Carnation");

    cout << endl;

    cout << "Get the flower list." << endl;
    shop1->showFlowerList();

    cout << "sell rose from shop1, shop2 will lose rose too." << endl;
    shop1->sellFlower("Rose");

    delete shop1;
    delete mediator;
}

int main() {
    testMediator();
    return 0;
}
