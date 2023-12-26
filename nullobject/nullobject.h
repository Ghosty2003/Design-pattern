#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual void doWork() = 0;
};

class RealEmployee : public Employee {
private:
    string name;
public:
    RealEmployee(string name) : name(name) {}
    void doWork() override {
        cout << name << " is doing work." << endl;
    }
};

class NullEmployee : public Employee {
public:
    void doWork() override {
        cout << "No employee available now!" << endl;
    }
};

class FlowerShop {
private:
    Employee* employee;
public:
    FlowerShop() : employee(new NullEmployee()) {}
    void hire(Employee* newEmployee) {
        delete employee;
        employee = newEmployee;
    }
    void fire() {
        delete employee;
        employee = new NullEmployee();
    }
    void checkEmployee() {
        employee->doWork();
    }
};

void test_nullobject() {
    FlowerShop shop;
    cout << "花店新开业！" << endl;
    cout << "老板喊员工干活" << endl;
    // 新店还没有员工
    shop.checkEmployee();

    // 老板雇佣了一个员工
    cout << "老板雇佣了Employee A" << endl;
    shop.hire(new RealEmployee("Employee A"));

    // Employee A开始工作
    cout << "老板再喊员工干活" << endl;
    shop.checkEmployee();

    // 老板开除员工
    cout << "Employee A 业绩不佳，惨遭开除" << endl;
    shop.fire();

    cout << "老板还想喊人干活" << endl;
    shop.checkEmployee();

    return;
}