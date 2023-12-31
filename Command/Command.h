#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// 命令接口
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// 接收者：处理订单的具体逻辑
class OrderReceiver {
public:
    void processOrder(const std::string &order) {
        std::cout << "处理订单: " << order << std::endl;
        // 添加订单到订单系统
        addOrderToSystem(order);
    }

    void cancelOrder(const std::string &order) {
        std::cout << "取消订单: " << order << std::endl;
        // 从订单系统中移除订单
        removeOrderFromSystem(order);
    }

private:
    void addOrderToSystem(const std::string &order) {
        // 实现添加订单到订单系统的逻辑
        std::cout << "订单系统接收订单: " << order << std::endl;
    }

    void removeOrderFromSystem(const std::string &order) {
        // 实现从订单系统中移除订单的逻辑
        std::cout << "订单系统取消订单: " << order << std::endl;
    }
};

// 具体命令：下单
class PlaceOrderCommand : public Command {
private:
    OrderReceiver &receiver;
    std::string order;
public:
    PlaceOrderCommand(OrderReceiver &receiver, const std::string &order)
        : receiver(receiver), order(order) {}
    void execute() override {
        cout << "要购买: " << order << endl;
        receiver.processOrder(order);
    }
    void undo() override {
        std::cout << "正在撤回: " << order << "的订单" << std::endl;
        receiver.cancelOrder(order);
    }
};

// 请求者：发送命令
class FlowerShop {
private:
    std::vector<std::shared_ptr<Command>> commandHistory;
public:
    void setCommand(const std::shared_ptr<Command>& command) {
        std::cout << "出现了新的客户！" << std::endl;
        commandHistory.push_back(command);
    }

    void submitOrder() {
        std::cout << "用户进行了下单" << std::endl;
        if (!commandHistory.empty()) {
            auto& command = commandHistory.back();
            command->execute();
        }
    }

    void undoOrder() {
        if (!commandHistory.empty()) {
            auto& command = commandHistory.back();
            std::cout << "正在撤销订单..." << std::endl;
            command->undo();
            commandHistory.pop_back();
        }
    }
};

void testCommand();
