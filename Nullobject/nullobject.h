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
        cout << "No employee available now! (�ն����Ĭ����Ϊ)" << endl;
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
    cout << "�����¿�ҵ��" << endl;
    cout << "�ϰ庰Ա���ɻ�" << endl;
    // �µ껹û��Ա��
    shop.checkEmployee();

    // �ϰ��Ӷ��һ��Ա��
    cout << "�ϰ��Ӷ��Employee A" << endl;
    shop.hire(new RealEmployee_zsp("Employee A"));

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