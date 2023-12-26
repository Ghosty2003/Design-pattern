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
    cout << "�����¿�ҵ��" << endl;
    cout << "�ϰ庰Ա���ɻ�" << endl;
    // �µ껹û��Ա��
    shop.checkEmployee();

    // �ϰ��Ӷ��һ��Ա��
    cout << "�ϰ��Ӷ��Employee A" << endl;
    shop.hire(new RealEmployee("Employee A"));

    // Employee A��ʼ����
    cout << "�ϰ��ٺ�Ա���ɻ�" << endl;
    shop.checkEmployee();

    // �ϰ忪��Ա��
    cout << "Employee A ҵ�����ѣ����⿪��" << endl;
    shop.fire();

    cout << "�ϰ廹�뺰�˸ɻ�" << endl;
    shop.checkEmployee();

    return;
}