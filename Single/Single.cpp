// SingletonFlowerShop.cpp


#include "Single.h"

using namespace std;


// ��ʼ����̬��Ա����
SalesStatistics* SalesStatistics::instance = nullptr;

// ��ȡ����ͳ��ʵ���ľ�̬����
SalesStatistics* SalesStatistics::getInstance() {
    if (!instance) {               // �����NULL
        instance = new SalesStatistics();  // ����ʵ��
    }
    return instance;
}

// ���ۻ����ķ���
void SalesStatistics::sellBouquet(const string& bouquetName, int price) {
    cout << "���������˻�����" << bouquetName << "���ۼۣ�" << price << "Ԫ" << endl;

    totalSales += price;  // ���������۶�
    totalBouquetsSold++;  // �����ܻ���������
}

// ���Ե���ģʽ�ĺ���
void testSingle() {
    // ��ȡ����ͳ��ʵ��
    SalesStatistics* statistics = SalesStatistics::getInstance();

    // ģ���û�������
    statistics->sellBouquet("õ�廨��", 50);
    statistics->sellBouquet("�ٺϻ���", 40);
    statistics->sellBouquet("�����㻨��", 30);

    // ��ӡ����ͳ����Ϣ
    std::cout << "�����۶" << statistics->getTotalSales() << "Ԫ" << std::endl;
    std::cout << "�ܻ�����������" << statistics->getTotalBouquetsSold() << "��" << std::endl;
}
