#include"Iterator.h"
void  testIterator() {
    srand(time(0));

    
    // ��������
    FlowerShopxlj2 flowerShop;
    flowerShop.addFlowerType("õ��");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("�ٺ�");
    flowerShop.addFlowerType("����ܰ");
    flowerShop.addFlowerType("ĵ��");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("�¼�");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("������");
    // ��ȡ������
    Iterator* iterator = flowerShop.createIterator();
    std::cout << "***************************************����****************************************" << std::endl;
    
    int m = 1;
    // ������������������ʻ�
    while (iterator->hasNext()) {
        const std::string& flowerType = iterator->next();
        int color = rand() % 15 + 1;
        cct_setcolor(COLOR_BLACK, color);
        int n = 0;
        while (n != m) {
            n++;
            std::cout << "    ";
        }
            std::cout << flowerType << std::endl;
            m++;
    }
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        delete iterator; // �ͷŵ������ڴ�
    
}
