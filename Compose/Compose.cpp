#include "Compose.h"
#include<sstream>
#include<string>

// �ͻ��˴��룬���ڴ�ӡ��������Ĳ������
void flowerShopClientCode(FlowerComponentGyy* component) {
    // ��ȡ��������Ĳ������
    string output_ = component->Operation();

    // ���������������ӡ
    std::istringstream ss(output_);
    std::string token;
    cout << "*��Ʒ����*��";
    static int count = 1;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE - (count++));
    while (std::getline(ss, token, ',')) {
        std::cout << token;
    }
}

// ʾ�����������ڲ������ģʽ�Ĺ���
void testCompose() {
    // ������һ���ܶ���
    FlowerComponentGyy* product1 = new SingleFlower("*õ�廨��*");
    FlowerComponentGyy* product2 = new SingleFlower("*����ܰ����*");
    FlowerComponentGyy* product3 = new SingleFlower("*�����㻨��*");

    // ����������װ���󣬲���ӵ�һ���ܶ���
    FlowerComponentGyy* set1 = new FlowerSet("*���˽��ر���װ*");
    set1->Add(product1);
    set1->Add(product2);

    // ����������װ���󣬲���ӵ�һ���ܶ��������������װ����
    FlowerComponentGyy* set2 = new FlowerSet("*���������װ*");
    set2->Add(product3);
    set2->Add(product3);  // �����ͬ�ĵ�һ���ܶ���
    set2->Add(product1);

    // ���ÿ���̨��ɫ�������������
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

    // ��ӡ��һ���ܺͻ�����װ�Ĳ������
    flowerShopClientCode(product1);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(product2);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(set1);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;
    flowerShopClientCode(set2);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << std::endl;

    // �ָ�����̨��ɫ
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);

    // �ͷŶ�̬������ڴ�
    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;
}
