#include "Facade.h"
#include <vector>

class InventorySystem;
class OrderProcessingSystem;
class CustomerServiceSystem;
class FlowerShopFacade;

// 实现子系统1
void InventorySystem::checkInventory() {
    std::cout << "检查花卉库存..." << std::endl;
}

void InventorySystem::updateInventory() {
    std::cout << "更新花卉库存..." << std::endl;
}

// 实现子系统2
void OrderProcessingSystem::placeOrder() {
    std::cout << "下单购买花卉..." << std::endl;
}

void OrderProcessingSystem::processPayment() {
    std::cout << "处理订单支付..." << std::endl;
}

// 实现子系统3
void CustomerServiceSystem::provideAssistance() {
    std::cout << "提供客户服务..." << std::endl;
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
}

// 新增安排活动的方法
void FlowerShopFacade::arrangeEvent() {
    std::cout << "欢迎光临花店，为顾客安排花卉装饰服务！" << std::endl;
    std::cout << "花卉装饰安排完成！" << std::endl;
}

// 新增送花服务的方法
void FlowerShopFacade::deliverFlowers() {
    std::cout << "欢迎光临花店，为顾客安排送花服务！" << std::endl;
    std::cout << "花卉已成功送达！" << std::endl;
}

// 新增随机分配活动的方法
void FlowerShopFacade::assignRandomActivity() {
    std::vector<void (FlowerShopFacade::*)()> activities = {
        &FlowerShopFacade::purchaseFlowers,
        &FlowerShopFacade::arrangeEvent,
        &FlowerShopFacade::deliverFlowers
    };


    // 随机选择一个活动
    int randomIndex = rand() % 3;
    (this->*activities[randomIndex])();  // 调用选择的活动
}

void testFacade() {

    srand((unsigned)time(0));

    FlowerShopFacade flowerShopGYYF;

    std::cout << "*~正在为顾客随机分配花店活动~*" << std::endl;

    for (int i = 1; i <= 3; i++) {
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        std::cout << "第 " << i << " 批顾客来到花店" << std::endl;
        cct_setcolor(COLOR_BLACK, COLOR_HWHITE - i);
        flowerShopGYYF.assignRandomActivity();
        std::cout << std::endl;
    }

    cct_setcolor(COLOR_BLACK, COLOR_WHITE);

}
