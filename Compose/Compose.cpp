#include "Compose.h"
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>

class FlowerComponent;

void flowerShopClientCode(FlowerComponent* component) {
    string output_ = component->Operation();

    std::istringstream ss(output_);
    std::string token;
    cout << "*��Ʒ����*��";
    static int count = 1;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE-(count++));
    while (std::getline(ss,token,',')) {

        std::cout << token;
    }
    if (count == 15)
        count = 0;
}

FlowerComponent* chooseFlowerBouquet() {
    // �ṩ����ѡ��
    std::cout << "�����������������װ(����0�˳�)��" << std::endl;
    std::cout << "1. õ�廨��  2. ����ܰ����  3. �����㻨��" << std::endl;
    std::cout << "���س�������ϣ�" ;

    std::string userInput;
    std::getline(std::cin, userInput);

    if (userInput == "0") {
        return nullptr; // �û�ѡ���˳������ؿ�ָ��
    }

    FlowerSet* userBouquet = new FlowerSet("*�û�������װ*");

    for (char c : userInput) {
        switch (c) {
        case '1':
            userBouquet->Add(new SingleFlower("*õ�廨��*"));
            break;
        case '2':
            userBouquet->Add(new SingleFlower("*����ܰ����*"));
            break;
        case '3':
            userBouquet->Add(new SingleFlower("*�����㻨��*"));
            break;
        default:
            std::cerr << "��Чѡ�" << c << std::endl;
            delete userBouquet;
            return nullptr; // �û�������Чѡ����ؿ�ָ��
        }
    }

    return userBouquet;
}



void testCompose() {
    FlowerComponent* product1 = new SingleFlower("*õ�廨��*");
    FlowerComponent* product2 = new SingleFlower("*����ܰ����*");
    FlowerComponent* product3 = new SingleFlower("*�����㻨��*");
    FlowerComponent* set1 = new FlowerSet("*���˽��ر���װ*");
    set1->Add(product1);
    set1->Add(product2);
    FlowerComponent* set2 = new FlowerSet("*���������װ*");
    set2->Add(product3);
    set2->Add(product3);
    set2->Add(product1);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
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
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    delete product1;
    delete product2;
    delete set1;
    delete product3;
    delete set2;

    // ѡ���û�����
    while (1) {
        FlowerComponent* userBouquet = chooseFlowerBouquet();
        if (userBouquet == nullptr)
            break;
        if (userBouquet) {
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
            flowerShopClientCode(userBouquet);
            cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
            std::cout << std::endl;
            cct_setcolor(COLOR_BLACK, COLOR_WHITE);
            delete userBouquet;
        }
    }
}
