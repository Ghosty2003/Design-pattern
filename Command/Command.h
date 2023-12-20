#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// ����ӿ�
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// �����ߣ��������ľ����߼�
class OrderReceiver {
public:
    void processOrder(const std::string &order) {
        std::cout << "������: " << order << std::endl;
    }
};

// ��������µ�
class PlaceOrderCommand : public Command {
private:
    OrderReceiver &receiver;
    std::string order;
public:
    PlaceOrderCommand(OrderReceiver &receiver, const std::string &order)
        : receiver(receiver), order(order) {}
    void execute() override {
        cout << "Ҫ����: " << order << endl;
        receiver.processOrder(order);
    }
    void undo() override {
        std::cout << "���ڳ���: " << order << "�Ķ���" << std::endl;
    }
};

// �����ߣ���������
class FlowerShop {
private:
    std::vector<std::shared_ptr<Command>> commandHistory;
public:
    void setCommand(const std::shared_ptr<Command>& command) {
        std::cout << "�������µĿͻ���" << std::endl;
        commandHistory.push_back(command);
    }

    void submitOrder() {
        std::cout << "�û��������µ�" << std::endl;
        if (!commandHistory.empty()) {
            auto& command = commandHistory.back();
            command->execute();
        }
    }

    void undoOrder() {
        if (!commandHistory.empty()) {
            auto& command = commandHistory.back();
            std::cout << "���ڳ�������..." << std::endl;
            command->undo();
            commandHistory.pop_back();
        }
    }
};

void testCommand();
