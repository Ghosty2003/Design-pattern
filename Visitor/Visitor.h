#pragma once
#include <iostream>
#include <vector>


void  testVisitor();
// 前置声明
class FreshFlower;
class PottedPlant;

// 抽象访问者
class Visitor {
public:
    virtual void visit(FreshFlower& flower) = 0;
    virtual void visit(PottedPlant& plant) = 0;
};


// 具体访问者 - 营销操作
class MarketingVisitor : public Visitor {
public:
    void visit(FreshFlower& flower) override {
        std::cout << "店员检查鲜花的新鲜度" << std::endl;

    }

    void visit(PottedPlant& plant) override {
        std::cout << "店员检查盆栽中土壤湿度和养分" << std::endl;
    }
};
// 具体访问者 - 营销操作
class CustomerVisitor : public Visitor {
public:
    void visit(FreshFlower& flower) override {
        std::cout << "顾客挑选鲜花" << std::endl;
    }

    void visit(PottedPlant& plant) override {
        std::cout << "顾客挑选盆栽" << std::endl;
    }
};
// 抽象元素类
class FlowerElement {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// 具体元素类 - 鲜花
class FreshFlower : public FlowerElement {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

// 具体元素类 - 盆栽
class PottedPlant : public FlowerElement {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};



