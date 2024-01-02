#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>

using namespace std;
// �����ӿ�
class IBouquetRQX {
public:
    virtual void deliver(std::string address) = 0;
};

// ����???
class FlowershopRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// �ͻ�����???
class DeliveryProxyRQX : public IBouquetRQX {
private:
    FlowershopRQX* flowerShop;
public:
    DeliveryProxyRQX();
    void deliver(std::string address) override;
};

// ���󹤳�ģʽ

// ǰ������
class HighEndBouquetRQX;
class EconomyBouquetRQX;

// ���������ӿ�
class IBouquetFactoryRQX {
public:
    virtual IBouquetRQX* createBouquet() = 0;
};

// �߶˻���???
class HighEndBouquetRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// �����ͻ�����
class EconomyBouquetRQX : public IBouquetRQX {
public:
    void deliver(std::string address) override;
};

// �߶˻�������
class HighEndBouquetFactoryRQX : public IBouquetFactoryRQX {
public:
    IBouquetRQX* createBouquet() override;
private:
    std::string Hf[2];
};

// �����ͻ�����???
class EconomyBouquetFactoryRQX : public IBouquetFactoryRQX {
public:
    IBouquetRQX* createBouquet() override;
private:
    std::string Ef[2];
};

void testAbstractFactory();
