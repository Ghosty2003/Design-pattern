// SingletonFlowerShop.h

#pragma once

#include <iostream>
#include <string>

using namespace std;

class SalesStatistics {
private:
    static SalesStatistics* instance;  // 单例实例

    int totalSales;  // 总销售额
    int totalBouquetsSold;  // 总花束销售量

    // 私有构造函数，防止直接创建对象
    SalesStatistics() : totalSales(0), totalBouquetsSold(0) {}

public:
    // 获取销售统计实例的静态方法
    static SalesStatistics* getInstance();

    // 销售花束的方法
    void sellBouquet(const string& bouquetName, int price);

    // 获取总销售额
    int getTotalSales() const { return totalSales; }

    // 获取总花束销售量
    int getTotalBouquetsSold() const { return totalBouquetsSold; }
};

// 测试单例模式的函数
void testSingle();
