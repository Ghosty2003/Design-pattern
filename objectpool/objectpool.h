#include <list>
#include <iostream>
using namespace std;

class Customer {
private:
    string name;
public:
    Customer(string name) : name(name) {}
    void setName(string name) {
        this->name = name;
    }
    void use() {
        cout << name << " is being served." << endl;
    }
    string getName() {
        return this->name;
    }
};

class ObjectPool {
private:
    list<Customer*> customers;
public:
    Customer* getCustomer(string name) {
        Customer* customer;
        if (customers.empty()) {
            customer = new Customer(name);
        }
        else {
            customer = customers.front();
            customers.pop_front();
        }
        customer->setName(name);
        return customer;
    }

    void returnCustomer(Customer* customer) {
        cout << customer->getName() << " has left." << endl;
        customers.push_back(customer);
    }
};

void test_objectpool() {
    ObjectPool pool;

    // 顾客A进入花店
    Customer* customerA = pool.getCustomer("Customer A");
    customerA->use();

    // 顾客B进入花店
    Customer* customerB = pool.getCustomer("Customer B");
    customerB->use();

    // 顾客B离开
    std::cout << "Customer B buys a bouquet of lavender." << std::endl;
    pool.returnCustomer(customerB);

    // 顾客C进入花店，此时这个指针分配的是对象池list首部的指针，也就是顾客B离开时push_back进去的、已经初始化过的内存
    Customer* customerC = pool.getCustomer("Customer C");
    customerC->use();

    // 顾客A离开
    std::cout << "Customer A buys a bouquet of irises." << std::endl;
    pool.returnCustomer(customerA);

    // 顾客C离开
    std::cout << "Customer C buys a pot of bell orchids." << std::endl;
    pool.returnCustomer(customerC);
}