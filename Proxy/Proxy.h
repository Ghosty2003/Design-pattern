// #pragma once

// using namespace std;

// class IBouquet {
// public:
//     virtual void deliver(std::string address) = 0;
// };

// class FlowerShop : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };
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

// class HighEndBouquet : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };

// class EconomyBouquet : public IBouquet {
// public:
//     void deliver(std::string address) override;
// };

// class HighEndBouquetFactory : public IBouquetFactory {
// public:
//     IBouquet* createBouquet() override;
// private:
//     std::string Hf[2];
// };

// class EconomyBouquetFactory : public IBouquetFactory {
// public:
//     IBouquet* createBouquet() override;
// private:
//     std::string Ef[2];
// };

// int testProxy();
