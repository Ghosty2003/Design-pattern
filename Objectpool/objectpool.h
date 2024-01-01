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
            cout << "����ؿգ���ʼ������" << name << endl;
        }
        else {
            cout << "������г�ʼ���Ķ��󣬵��ó��е�һ�����󲢸�ֵ�����" << name << "ʵ��" << endl;
            customer = customers.front();
            customer->setName(name);
            customers.pop_front();
        }
        return customer;
    }
    void returnCustomer(Customer_zsp* customer) {
        cout << customer->getName() << " has left." << "��������������У�����һ��ʹ��" << endl;
        customers.push_back(customer);
    }
};

void test_objectpool() {
    ObjectPool_zsp pool;

    // �˿�A���뻨��
    Customer_zsp* customerA = pool.getCustomer("Customer A");
    customerA->use();

    // �˿�B���뻨��
    Customer_zsp* customerB = pool.getCustomer("Customer B");
    customerB->use();

    // �˿�B�뿪
    std::cout << "Customer B buys a bouquet of lavender." << std::endl;
    pool.returnCustomer(customerB);

    // �˿�C���뻨�꣬��ʱ���ָ�������Ƕ����list�ײ���ָ�룬Ҳ���ǹ˿�B�뿪ʱpush_back��ȥ�ġ��Ѿ���ʼ�������ڴ�
    Customer_zsp* customerC = pool.getCustomer("Customer C");
    customerC->use();

    // �˿�A�뿪
    std::cout << "Customer A buys a bouquet of irises." << std::endl;
    pool.returnCustomer(customerA);

    // �˿�C�뿪
    std::cout << "Customer C buys a pot of bell orchids." << std::endl;
    pool.returnCustomer(customerC);
}