#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

class BuyCommand : public Command {
private:
    string item;
    int quantity;
public:
    BuyCommand(string item, int quantity) : item(item), quantity(quantity) {}
    void execute() override {
        cout << "the employee buys " << quantity << " " << item << endl;
    }
};

class Interpreter {
private:
    map<string, Command*> commands;
public:
    void interpret(string command) {
        istringstream iss(command);
        string action, item;
        int quantity;
        iss >> action >> quantity >> item;
        if (action == "buy") {
            commands[action] = new BuyCommand(item, quantity);
            commands[action]->execute();
        }
        else {
            cout << "the employee doesn't know how to satisfy the need." << endl;
        }
    }
};

void test_interpreter() {
    Interpreter interpreter;
    cout << "�ϰ���Ա����10��õ�廨����˵��buy 10 roses" << endl;
    interpreter.interpret("buy 10 roses");
    cout << "�ϰ���Ա����5��ٺϻ�����˵��buy 5 lilies" << endl;
    interpreter.interpret("buy 5 lilies");
    cout << "�ϰ���Ա����һ̨�յ�����˵��repair 1 air-conditioner" << endl;
    interpreter.interpret("repair 1 air-conditioner");
    return;
};