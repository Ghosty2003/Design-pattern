#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "TransferObject.h"

void outputAll(FlowerBO_YH flowerObject) {
    vector<FlowerVO_YH> flowerList = flowerObject.getAllFlowers();
    cout << "Flower list: " << endl;
    cout << setiosflags(ios::left);
    for (vector<FlowerVO_YH>::iterator iter = flowerList.begin(); iter != flowerList.end(); iter++) {
        cout << setw(20) << setfill(' ') << iter->getName() << setw(10) << setfill(' ') << iter->getColor() << iter->getQuantity() << endl;
    }
    cout << endl;
}

void testTransferObject() {
    FlowerBO_YH flowerObject;

    //插入花卉信息
    flowerObject.addFlower(FlowerVO_YH("rose", "red", 50));
    flowerObject.addFlower(FlowerVO_YH("tulip", "yellow", 30));
    flowerObject.addFlower(FlowerVO_YH("lily", "white", 20));
    flowerObject.addFlower(FlowerVO_YH("carnation", "pink", 40));

    cout << "out put all flowers：" << endl;
    outputAll(flowerObject);

    cout << endl << "change some flowers' number: " << endl;
    flowerObject.updateFlower(FlowerVO_YH("rose", "red", 100));
    flowerObject.updateFlower(FlowerVO_YH("tulip", "yellow", 50));

    cout << endl << "delete some flowers' information: " << endl;
    flowerObject.deleteFlower(flowerObject.getFlower("lily"));

    cout << endl;
    cout << "output flowers again: " << endl;
    outputAll(flowerObject);
}

int main() {
    testTransferObject();
    return 0;
}