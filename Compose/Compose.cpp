#include "Compose.h"

class FlowerComponent;

void pressEntertoContinue() {
    std::cout << "���س�������...";
    std::cin.ignore();  // �����û����룬�ȴ��س�
    std::cout << std::endl;
}

void flowerShopClientCode(FlowerComponent* component) {
    std::cout << "��Ʒ����: " << component->Operation() << std::endl;
    pressEntertoContinue();
}

void testCompose() {
    FlowerComponent* product1 = new SingleFlower("õ�廨��");
    FlowerComponent* product2 = new SingleFlower("����ܰ��ƿ");

    FlowerComponent* set1 = new FlowerSet("���˽��ر���װ");
    set1->Add(product1);
    set1->Add(product2);

    FlowerComponent* product3 = new SingleFlower("�����㻨ƿ");

    FlowerComponent* set2 = new FlowerSet("���������װ");
    set2->Add(product3);

    flowerShopClientCode(product1);
    flowerShopClientCode(product2);
    flowerShopClientCode(set1);
    flowerShopClientCode(set2);

    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;
}
