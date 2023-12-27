#include "RAII.h"

void ResourceManagement::acquireResources() {
    std::cout << "获取花卉、包装材料等资源..." << std::endl;
}

void ResourceManagement::releaseResources() {
    std::cout << "释放花卉、包装材料等资源..." << std::endl;
}

void FlowerShopGYYR::sellFlowers() {
    std::cout << "花店正在售卖花卉..." << std::endl;
}

void FlowerShopGYYR::arrangeEvent() {
    std::cout << "花店正在安排活动..." << std::endl;
}