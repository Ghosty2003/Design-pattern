#include"Iterator.h"

void  testIterator() {
    // ��������
    FlowerShop2 flowerShop;
    flowerShop.addFlowerType("õ��");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("�ٺ�");
    flowerShop.addFlowerType("����ܰ");

    // ��ȡ������
    Iterator* iterator = flowerShop.createIterator();

    // ������������������ʻ�
    while (iterator->hasNext()) {
        const std::string& flowerType = iterator->next();
        std::cout << "�����У�" << flowerType << std::endl;
    }

    delete iterator; // �ͷŵ������ڴ�
}
