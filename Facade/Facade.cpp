#include "Facade.h"
#include <vector>

class InventorySystem;
class OrderProcessingSystem;
class CustomerServiceSystem;
class FlowerShopFacade;

void pressEnterToContinue() {
    std::cout << "按回车键继续...";
    std::cin.ignore();  // 忽略用户输入，等待回车
    std::cout << std::endl;
}

// 实现子系统1
void InventorySystem::checkInventory() {
    std::cout << "检查花卉库存..." << std::endl;
    pressEnterToContinue();
}

void InventorySystem::updateInventory() {
    std::cout << "更新花卉库存..." << std::endl;
    pressEnterToContinue();
}

// 实现子系统2
void OrderProcessingSystem::placeOrder() {
    std::cout << "下单购买花卉..." << std::endl;
    pressEnterToContinue();
}

void OrderProcessingSystem::processPayment() {
    std::cout << "处理订单支付..." << std::endl;
    pressEnterToContinue();
}

// 实现子系统3
void CustomerServiceSystem::provideAssistance() {
    std::cout << "提供客户服务..." << std::endl;
    pressEnterToContinue();
}

// 实现花店外观类（Facade）
FlowerShopFacade::FlowerShopFacade() {
    // 初始化子系统
}

FlowerShopFacade::~FlowerShopFacade() {
    // 销毁子系统
}

// 实现购买花卉的方法
void FlowerShopFacade::purchaseFlowers() {
    std::cout << "欢迎光临花店！" << std::endl;
    InventorySystem().checkInventory();
    OrderProcessingSystem().placeOrder();
    OrderProcessingSystem().processPayment();
    CustomerServiceSystem().provideAssistance();
    std::cout << "感谢您光临我们的店铺！" << std::endl;
    pressEnterToContinue();
}

// 新增安排活动的方法
void FlowerShopFacade::arrangeEvent() {
    std::cout << "欢迎来到花店活动安排服务！" << std::endl;
    std::cout << "活动安排完成！" << std::endl;
    pressEnterToContinue();
}

// 新增送花服务的方法
void FlowerShopFacade::deliverFlowers() {
    std::cout << "欢迎来到花店送花服务！" << std::endl;
    std::cout << "花卉已成功送达！" << std::endl;
    pressEnterToContinue();
}

// 新增随机分配活动的方法
void FlowerShopFacade::assignRandomActivity() {
    std::vector<void (FlowerShopFacade::*)()> activities = {
        &FlowerShopFacade::purchaseFlowers,
        &FlowerShopFacade::arrangeEvent,
        &FlowerShopFacade::deliverFlowers
    };

    // 随机选择一个活动
    int randomIndex = rand() % activities.size();
    (this->*activities[randomIndex])();  // 调用选择的活动
}

void testFacade() {
    srand((unsigned)time(0));

    FlowerShopFacade flowerShopGYYF;

    for (int i = 1; i <= 3; i++) {
        std::cout << "第 " << i << " 批顾客来到花店" << std::endl;
        flowerShopGYYF.assignRandomActivity();
        std::cout << std::endl;
        pressEnterToContinue();
    }
}

