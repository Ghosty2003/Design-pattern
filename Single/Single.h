// SingletonFlowerShop.h

#pragma once

#include <iostream>
#include <string>

using namespace std;

class SalesStatistics {
private:
    static SalesStatistics* instance;  // ����ʵ��

    int totalSales;  // �����۶�
    int totalBouquetsSold;  // �ܻ���������

    // ˽�й��캯������ֱֹ�Ӵ�������
    SalesStatistics() : totalSales(0), totalBouquetsSold(0) {}

public:
    // ��ȡ����ͳ��ʵ���ľ�̬����
    static SalesStatistics* getInstance();

    // ���ۻ����ķ���
    void sellBouquet(const string& bouquetName, int price);

    // ��ȡ�����۶�
    int getTotalSales() const { return totalSales; }

    // ��ȡ�ܻ���������
    int getTotalBouquetsSold() const { return totalBouquetsSold; }
};

// ���Ե���ģʽ�ĺ���
void testSingle();
