#pragma once
#include <iostream>
#include <string>

class ResourceManagement {
public:
    ResourceManagement() {
        acquireResources();
        std::cout << "花店资源准备就绪！" << std::endl;
    }

    ~ResourceManagement() {
        releaseResources();
        std::cout << "花店资源清理完成！" << std::endl;
    }

    void acquireResources();

    void releaseResources();
};

class FlowerShop {
public:
    FlowerShop() {
        std::cout << "欢迎光临花店！" << std::endl;
    }

    void sellFlowers();
    void arrangeEvent();

    ~FlowerShop() {
        std::cout << "感谢您的光临！" << std::endl;
    }
};