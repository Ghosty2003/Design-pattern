#pragma once
#include <iostream>
#include <string>

class ResourceManagement {
public:
    ResourceManagement() {
        acquireResources();
        std::cout << "������Դ׼��������" << std::endl;
    }

    ~ResourceManagement() {
        releaseResources();
        std::cout << "������Դ������ɣ�" << std::endl;
    }

    void acquireResources();

    void releaseResources();
};

class FlowerShop {
public:
    FlowerShop() {
        std::cout << "��ӭ���ٻ��꣡" << std::endl;
    }

    void sellFlowers();
    void arrangeEvent();

    ~FlowerShop() {
        std::cout << "��л���Ĺ��٣�" << std::endl;
    }
};