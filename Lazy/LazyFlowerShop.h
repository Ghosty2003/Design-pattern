// LazyFlowerShop.h

#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

// ������
class FlowerBouquet {
private:
    string name;

    // ��̬��Ա���������ڴ洢�Ѵ����Ļ�������ͨ������������
    static map<string, FlowerBouquet*> types;

    // ˽�й��캯������ֱֹ�Ӵ�������
    FlowerBouquet(const string& name);

public:
    // ��ȡ����ʵ���ľ�̬����
    static FlowerBouquet* getFlowerBouquet(const string& name);

    // ��ӡ��ǰ�Ѵ����Ļ�������
    static void printCurrentTypes();
};

// �û���
class User {
private:
    string name;
    string preferredFlower;
    string defaultAddress;
    string contactNumber;

public:
    // ���캯�����û���ʼ��ʱ��������
    User(const string& name);

    // ���û���ƫ��
    void setPreferredFlower(const string& flower);

    // ����Ĭ���ջ���ַ
    void setDefaultAddress(const string& address);

    // ������ϵ��ʽ
    void setContactNumber(const string& number);

    // �µ�������Ӧ���û����õ�ƫ�ú�Ĭ����Ϣ
    void placeOrder(const string& flowerName);

    // ��ȡ�û����õĻ���ƫ��
    const string& getPreferredFlower() const { return preferredFlower; }
};

// ���Զ��Գ�ʼģʽ�ĺ���
void testLazyInitialization();