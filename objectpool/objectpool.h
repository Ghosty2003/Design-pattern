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

    // �˿�A���뻨��
    Customer* customerA = pool.getCustomer("Customer A");
    customerA->use();

    // �˿�B���뻨��
    Customer* customerB = pool.getCustomer("Customer B");
    customerB->use();

    // �˿�B�뿪
    std::cout << "Customer B buys a bouquet of lavender." << std::endl;
    pool.returnCustomer(customerB);

    // �˿�C���뻨�꣬��ʱ���ָ�������Ƕ����list�ײ���ָ�룬Ҳ���ǹ˿�B�뿪ʱpush_back��ȥ�ġ��Ѿ���ʼ�������ڴ�
    Customer* customerC = pool.getCustomer("Customer C");
    customerC->use();

    // �˿�A�뿪
    std::cout << "Customer A buys a bouquet of irises." << std::endl;
    pool.returnCustomer(customerA);

    // �˿�C�뿪
    std::cout << "Customer C buys a pot of bell orchids." << std::endl;
    pool.returnCustomer(customerC);
}