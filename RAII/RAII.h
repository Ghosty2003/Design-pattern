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

class FlowerShopGYYR {
public:
    FlowerShopGYYR() {
        std::cout << "��ӭ���ٻ��꣡" << std::endl;
    }

    void sellFlowers();
    void arrangeEvent();

    ~FlowerShopGYYR() {
        std::cout << "��л���Ĺ��٣�" << std::endl;
    }
};