#pragma once
#include <iostream>
#include <vector>


void  testVisitor();
// ǰ������
class FreshFlower;
class PottedPlant;

// ���������
class Visitor {
public:
    virtual void visit(FreshFlower& flower) = 0;
    virtual void visit(PottedPlant& plant) = 0;
};


// ��������� - Ӫ������
class MarketingVisitor : public Visitor {
public:
    void visit(FreshFlower& flower) override {
        std::cout << "��Ա����ʻ������ʶ�" << std::endl;

    }

    void visit(PottedPlant& plant) override {
        std::cout << "��Ա�������������ʪ�Ⱥ�����" << std::endl;
    }
};
// ��������� - Ӫ������
class CustomerVisitor : public Visitor {
public:
    void visit(FreshFlower& flower) override {
        std::cout << "�˿���ѡ�ʻ�" << std::endl;
    }

    void visit(PottedPlant& plant) override {
        std::cout << "�˿���ѡ����" << std::endl;
    }
};
// ����Ԫ����
class FlowerElement {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// ����Ԫ���� - �ʻ�
class FreshFlower : public FlowerElement {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

// ����Ԫ���� - ����
class PottedPlant : public FlowerElement {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};



