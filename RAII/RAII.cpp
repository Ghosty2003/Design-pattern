#include "RAII.h"

void ResourceManagement::acquireResources() {
    std::cout << "��ȡ���ܡ���װ���ϵ���Դ..." << std::endl;
}

void ResourceManagement::releaseResources() {
    std::cout << "�ͷŻ��ܡ���װ���ϵ���Դ..." << std::endl;
}

void FlowerShop::sellFlowers() {
    std::cout << "����������������..." << std::endl;
}

void FlowerShop::arrangeEvent() {
    std::cout << "�������ڰ��Ż..." << std::endl;
}