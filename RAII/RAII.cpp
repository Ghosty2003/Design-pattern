#include "RAII.h"

void ResourceManagement::acquireResources() {
    std::cout << "��ȡ���ܡ���װ���ϵ���Դ..." << std::endl;
}

void ResourceManagement::releaseResources() {
    std::cout << "�ͷŻ��ܡ���װ���ϵ���Դ..." << std::endl;
}

void FlowerShopGYYR::sellFlowers() {
    std::cout << "����������������..." << std::endl;
}

void FlowerShopGYYR::arrangeEvent() {
    std::cout << "�������ڰ��Ż..." << std::endl;
}