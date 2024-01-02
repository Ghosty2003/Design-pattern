// SingletonFlowerShop.cpp


#include "Single.h"

using namespace std;


// 初始化静态成员变量
SalesStatistics* SalesStatistics::instance = nullptr;

// 获取销售统计实例的静态方法
SalesStatistics* SalesStatistics::getInstance() {
    if (!instance) {               // 如果是NULL
        instance = new SalesStatistics();  // 创建实例
    }
    return instance;
}

// 销售花束的方法
void SalesStatistics::sellBouquet(const string& bouquetName, int price) {
    cout << "花店销售了花束：" << bouquetName << "，售价：" << price << "元" << endl;

    totalSales += price;  // 更新总销售额
    totalBouquetsSold++;  // 更新总花束销售量
}

// 测试单例模式的函数
void testSingle() {
    // 获取销售统计实例
    SalesStatistics* statistics = SalesStatistics::getInstance();

    // 模拟用户购买花束
    statistics->sellBouquet("玫瑰花束", 50);
    statistics->sellBouquet("百合花束", 40);
    statistics->sellBouquet("郁金香花束", 30);

    // 打印销售统计信息
    std::cout << "总销售额：" << statistics->getTotalSales() << "元" << std::endl;
    std::cout << "总花束销售量：" << statistics->getTotalBouquetsSold() << "束" << std::endl;
}
