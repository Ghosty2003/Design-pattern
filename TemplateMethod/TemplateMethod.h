#pragma once
#include <iostream>
using namespace std;

class FlowerTemplate_wwj {
public:
    void produceFlower() {
        selectSeed();
        plant();
        water();
        fertilize();
    }

    virtual void selectSeed() = 0;
    virtual void plant() = 0;
    virtual void water() = 0;
    virtual void fertilize() = 0;

};

class Rose_wwj : public FlowerTemplate_wwj {
    void selectSeed();
    void plant();
    void water();
    void fertilize();
};

class Lily_wwj : public FlowerTemplate_wwj {
    void selectSeed();
    void plant();
    void water();
    void fertilize();
};

void testTemplateMethod();