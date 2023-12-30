#pragma once
#include <iostream>
#include <list>
#include <string>
#include "../utils/cct_tools.h"

// 花卉组件抽象类
class FlowerComponentGyy {
protected:
    FlowerComponentGyy* parent_; // 父组件指针
    std::string name; // 花卉组件的名称

public:
    // 构造函数
    FlowerComponentGyy(std::string name) : name(name), parent_(nullptr) {}

    // 添加子组件的虚拟方法
    virtual void Add(FlowerComponentGyy* component) {}

    // 移除子组件的虚拟方法
    virtual void Remove(FlowerComponentGyy* component) {}

    // 判断是否为组合对象的虚拟方法
    virtual bool IsComposite() const {
        return false;
    }

    // 设置父组件的虚拟方法
    virtual void SetParent(FlowerComponentGyy* parent) {
        parent_ = parent;
    }

    // 获取花卉组件的操作结果的纯虚拟方法
    virtual std::string Operation() const = 0;
};

// 单一花卉类，继承自花卉组件抽象类
class SingleFlower : public FlowerComponentGyy {
public:
    // 构造函数
    SingleFlower(std::string name) : FlowerComponentGyy(name) {}

    // 获取单一花卉的操作结果
    std::string Operation() const override {
        return "单一花卉: " + name;
    }
};

// 花束套装类，继承自花卉组件抽象类
class FlowerSet : public FlowerComponentGyy {
private:
    std::list<FlowerComponentGyy*> children_; // 子组件列表

public:
    // 构造函数
    FlowerSet(std::string name) : FlowerComponentGyy(name) {}

    // 添加子组件的实现方法
    void Add(FlowerComponentGyy* component) override {
        children_.push_back(component);
        component->SetParent(this);
    }

    // 移除子组件的实现方法
    void Remove(FlowerComponentGyy* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    // 判断是否为组合对象的实现方法
    bool IsComposite() const override {
        return true;
    }

    // 获取花束套装的操作结果的实现方法
    std::string Operation() const override {
        std::string result = "花束套装: " + name + " 包含 ";
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

// 客户端代码，用于打印花卉组件的操作结果
void flowerShopClientCode(FlowerComponentGyy* component);

// 示例方法，用于测试组合模式的功能
void testCompose();
