#include <list>
#include <iostream>
using namespace std;

class Customer_zsp {
private:
    string name;
public:
    Customer_zsp(string name) : name(name) {}
    void setName(string name) {
        this->name = name;
    }
    void use() {
        cout << name << " enters the flowershop and is being served." << endl;
    }
    string getName() {
        return this->name;
    }
};

class ObjectPool_zsp {
private:
    list<Customer_zsp*> customers;
public:
    Customer_zsp* getCustomer(string name) {
        Customer_zsp* customer;
        if (customers.empty()) {
            customer = new Customer_zsp(name);
            cout << "对象池空，初始化对象" << name << endl;
        }
        else {
            cout << "对象池有初始化的对象，调用池中第一个对象并赋值，获得" << name << "实例" << endl;
            customer = customers.front();
            customer->setName(name);
            customers.pop_front();
        }
        return customer;
    }
    void returnCustomer(Customer_zsp* customer) {
        cout << customer->getName() << " has left." << "将对象放入对象池中，供下一次使用" << endl;
        customers.push_back(customer);
    }
};

void test_objectpool() {
    ObjectPool_zsp pool;

    // 顾客A进入花店
    Customer_zsp* customerA = pool.getCustomer("Customer A");
    customerA->use();

    // 顾客B进入花店
    Customer_zsp* customerB = pool.getCustomer("Customer B");
    customerB->use();

    // 顾客B离开
    std::cout << "Customer B buys a bouquet of lavender." << std::endl;
    pool.returnCustomer(customerB);

    // 顾客C进入花店，此时这个指针分配的是对象池list首部的指针，也就是顾客B离开时push_back进去的、已经初始化过的内存
    Customer_zsp* customerC = pool.getCustomer("Customer C");
    customerC->use();

    // 顾客A离开
    std::cout << "Customer A buys a bouquet of irises." << std::endl;
    pool.returnCustomer(customerA);

    // 顾客C离开
    std::cout << "Customer C buys a pot of bell orchids." << std::endl;
    pool.returnCustomer(customerC);
}