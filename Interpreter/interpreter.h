#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class Command_zsp {
public:
    virtual void execute() = 0;
};

class BuyCommand_zsp : public Command_zsp {
private:
    string item;
    int quantity;
public:
    BuyCommand_zsp(string item, int quantity) : item(item), quantity(quantity) {}
    void execute() override {
        cout << "buys " << quantity << " " << item << endl;
    }
};

class WaterCommand_zsp : public Command_zsp {
private:
    string item;
    int quantity;
public:
    WaterCommand_zsp(string item, int quantity) : item(item), quantity(quantity) {}
    void execute() override {
        cout << "waters " << quantity << " " << item << endl;
    }
};

class DeliverCommand_zsp : public Command_zsp {
private:
    string item;
    int quantity;
public:
    DeliverCommand_zsp(string item, int quantity) : item(item), quantity(quantity) {}
    void execute() override {
        cout << "delivers " << quantity << " " << item << endl;
    }
};

class Interpreter_zsp {
private:
    map<string, Command_zsp*> commands;
public:
    void interpret(string command) {
        istringstream iss(command);
        string action, item;
        int quantity;
        iss >> action >> quantity >> item;
        if (action == "buy") {
            cout << "the employee understands the requirement and ";
            commands[action] = new BuyCommand_zsp(item, quantity);
            commands[action]->execute();
        }
        else if (action == "water") {
            cout << "the employee understands the requirement and ";
            commands[action] = new WaterCommand_zsp(item, quantity);
            commands[action]->execute();
        }
        else if (action == "deliver") {
            cout << "the employee understands the requirement and ";
            commands[action] = new DeliverCommand_zsp(item, quantity);
            commands[action]->execute();
        }
        else {
            cout << "the employee doesn't know how to satisfy the need." << endl;
        }
    }
};

void test_interpreter() {
    Interpreter_zsp interpreter;
    cout << "老板让员工买10朵玫瑰花，她说：buy 10 roses" << endl;
    interpreter.interpret("buy 10 roses");
    cout << "老板让员工给5朵百合花浇水，她说：water 5 lilies" << endl;
    interpreter.interpret("water 5 lilies");
    cout << "老板让员工运送4朵雏菊，她说：deliver 4 daisy" << endl;
    interpreter.interpret("deliver 4 daisy");
    cout << "老板让员工修一台空调，她说：repair 1 air-conditioner" << endl;
    interpreter.interpret("repair 1 air-conditioner");
    return;
};