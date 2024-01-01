#pragma once
#include <iostream>
#include <vector>
#include"../utils/cct_tools.h"
#include <string>
void  testIterator(); //测试函数
// 抽象迭代器
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual const std::string& next() = 0;

};

// 具体迭代器
class FlowerIterator : public Iterator {
private:
    const std::vector<std::string>& flowers;
    size_t index;

public:
    FlowerIterator(const std::vector<std::string>& flowerTypes)
        : flowers(flowerTypes), index(0) {}

    bool hasNext() const override {
        return index < flowers.size();
    }

    const std::string& next() override {
        return flowers[index++];
    }
};

// 花店聚合类
class FlowerShopxlj2 {
private:
    std::vector<std::string> flowerTypes;

public:
    void addFlowerType(const std::string& flowerType) {
        flowerTypes.push_back(flowerType);
    }

    // 获取迭代器
    Iterator* createIterator() const {
        return new FlowerIterator(flowerTypes);
    }
};
