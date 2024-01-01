#include <iostream>
#include <string>
using namespace std;

class Employee_zsp {
public:
    virtual void doWork() = 0;
};

class RealEmployee_zsp : public Employee_zsp {
private:
    string name;
public:
    RealEmployee_zsp(string name) : name(name) {}
    void doWork() override {
        cout << name << " is doing work." << endl;
    }
};

class NullEmployee_zsp : public Employee_zsp {
public:
    void doWork() override {
        cout << "No employee available now! (空对象的默认行为)" << endl;
    }
};

class FlowerShop_zsp {
private:
    Employee_zsp* employee;
public:
    FlowerShop_zsp() : employee(new NullEmployee_zsp()) {}
    void hire(Employee_zsp* newEmployee) {
        delete employee;
        employee = newEmployee;
    }
    void fire() {
        delete employee;
        employee = new NullEmployee_zsp();
    }
    void checkEmployee() {
        employee->doWork();
    }
};

void test_nullobject() {
    FlowerShop_zsp shop;
    cout << "花店新开业！" << endl;
    cout << "老板喊员工干活" << endl;
    // 新店还没有员工
    shop.checkEmployee();

    // 老板雇佣了一个员工
    cout << "老板雇佣了Employee A" << endl;
    shop.hire(new RealEmployee_zsp("Employee A"));

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