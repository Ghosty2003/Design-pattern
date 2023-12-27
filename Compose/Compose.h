#pragma once
#include <iostream>
#include <list>
#include <string>

class FlowerComponent {
protected:
    FlowerComponent* parent_;
    std::string name;

public:
    FlowerComponent(std::string name) : name(name), parent_(nullptr) {}

    virtual void Add(FlowerComponent* component) {}
    virtual void Remove(FlowerComponent* component) {}
    virtual bool IsComposite() const {
        return false;
    }

    virtual void SetParent(FlowerComponent* parent) {
        parent_ = parent;
    }

    virtual std::string Operation() const = 0;
};

class SingleFlower : public FlowerComponent {
public:
    SingleFlower(std::string name) : FlowerComponent(name) {}

    std::string Operation() const override {
        return "单一花卉: " + name;
    }
};

class FlowerSet : public FlowerComponent {
private:
    std::list<FlowerComponent*> children_;

public:
    FlowerSet(std::string name) : FlowerComponent(name) {}

    void Add(FlowerComponent* component) override {
        children_.push_back(component);
        component->SetParent(this);
    }

    void Remove(FlowerComponent* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    bool IsComposite() const override {
        return true;
    }

    std::string Operation() const override {
        std::string result = "花束套装: " + name + " 包含 ";
        for (const FlowerComponent* c : children_) {
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

void flowerShopClientCode(FlowerComponent* component);
void pressEntertoContinue();

void testCompose();