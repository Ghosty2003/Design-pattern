// LazyFlowerShop.h

#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

// 花束类
class FlowerBouquet {
private:
    string name;

    // 静态成员变量，用于存储已创建的花束对象，通过类型名索引
    static map<string, FlowerBouquet*> types;

    // 私有构造函数，防止直接创建对象
    FlowerBouquet(const string& name);

public:
    // 获取花束实例的静态方法
    static FlowerBouquet* getFlowerBouquet(const string& name);

    // 打印当前已创建的花束类型
    static void printCurrentTypes();
};

// 用户类
class User {
private:
    string name;
    string preferredFlower;
    string defaultAddress;
    string contactNumber;

public:
    // 构造函数，用户初始化时设置姓名
    User(const string& name);

    // 设置花束偏好
    void setPreferredFlower(const string& flower);

    // 设置默认收货地址
    void setDefaultAddress(const string& address);

    // 设置联系方式
    void setContactNumber(const string& number);

    // 下单方法，应用用户设置的偏好和默认信息
    void placeOrder(const string& flowerName);

    // 获取用户设置的花束偏好
    const string& getPreferredFlower() const { return preferredFlower; }
};

// 测试惰性初始模式的函数
void testLazyInitialization();