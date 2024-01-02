// #pragma once

// using namespace std;

// // 花束接口
// class IBouquet {
// public:
//     virtual void deliver(std::string address) = 0;
// };

// // 花店�?
// class FlowerShop : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };

// // 送货代理�?
// class DeliveryProxy : public IBouquet {
// private:
//     FlowerShop* flowerShop;
// public:
//     DeliveryProxy();
//     void deliver(std::string address) override;
// };

// // 抽象工厂模式

// // 前置声明
// class HighEndBouquet;
// class EconomyBouquet;

// // 花束工厂接口
// class IBouquetFactory {
// public:
//     virtual IBouquet* createBouquet() = 0;
// };

// // 高端花束�?
// class HighEndBouquet : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };

// // 经济型花束类
// class EconomyBouquet : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };

// // 高端花束工厂
// class HighEndBouquetFactory : public IBouquetFactory {
// public:
//     IBouquet* createBouquet() override;
// private:
//     std::string Hf[2];
// };

// // 经济型花束工�?
// class EconomyBouquetFactory : public IBouquetFactory {
// public:
//     IBouquet* createBouquet() override;
// private:
//     std::string Ef[2];
// };

// int testProxy();
