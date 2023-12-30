#pragma once
#include <iostream>
#include <list>
#include <string>
#include "../utils/cct_tools.h"

// �������������
class FlowerComponentGyy {
protected:
    FlowerComponentGyy* parent_; // �����ָ��
    std::string name; // �������������

public:
    // ���캯��
    FlowerComponentGyy(std::string name) : name(name), parent_(nullptr) {}

    // �������������ⷽ��
    virtual void Add(FlowerComponentGyy* component) {}

    // �Ƴ�����������ⷽ��
    virtual void Remove(FlowerComponentGyy* component) {}

    // �ж��Ƿ�Ϊ��϶�������ⷽ��
    virtual bool IsComposite() const {
        return false;
    }

    // ���ø���������ⷽ��
    virtual void SetParent(FlowerComponentGyy* parent) {
        parent_ = parent;
    }

    // ��ȡ��������Ĳ�������Ĵ����ⷽ��
    virtual std::string Operation() const = 0;
};

// ��һ�����࣬�̳��Ի������������
class SingleFlower : public FlowerComponentGyy {
public:
    // ���캯��
    SingleFlower(std::string name) : FlowerComponentGyy(name) {}

    // ��ȡ��һ���ܵĲ������
    std::string Operation() const override {
        return "��һ����: " + name;
    }
};

// ������װ�࣬�̳��Ի������������
class FlowerSet : public FlowerComponentGyy {
private:
    std::list<FlowerComponentGyy*> children_; // ������б�

public:
    // ���캯��
    FlowerSet(std::string name) : FlowerComponentGyy(name) {}

    // ����������ʵ�ַ���
    void Add(FlowerComponentGyy* component) override {
        children_.push_back(component);
        component->SetParent(this);
    }

    // �Ƴ��������ʵ�ַ���
    void Remove(FlowerComponentGyy* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    // �ж��Ƿ�Ϊ��϶����ʵ�ַ���
    bool IsComposite() const override {
        return true;
    }

    // ��ȡ������װ�Ĳ��������ʵ�ַ���
    std::string Operation() const override {
        std::string result = "������װ: " + name + " ���� ";
        for (const FlowerComponentGyy* c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + ", ";
            }
        }
        return result;
    }
};

// �ͻ��˴��룬���ڴ�ӡ��������Ĳ������
void flowerShopClientCode(FlowerComponentGyy* component);

// ʾ�����������ڲ������ģʽ�Ĺ���
void testCompose();
