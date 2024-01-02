#include"Iterator.h"
#include "../utils/cct_tools.h"
void  testIterator() {
    cct_cls();
    const char* sign[] = {
            "***************************************************************************************************",
            "*____   ____.__                __________                     .__                                 *",
            "*\\   \\ /   /|__| ______  _  __ \\______   \\__ _________   ____ |  |__ _____    ______ ____   ______*",
            "* \\   Y   / |  |/ __ \\ \\/ \\/ /  |     ___/  |  \\_  __ \\_/ ___\\|  |  \\\\__  \\  /  ___// __ \\ /  ___/*",
            "*  \\     /  |  \\  ___/\\     /   |    |   |  |  /|  | \\/\\  \\___|   Y  \\/ __ \\_\\___ \\\\  ___/ \\____\\ *",
            "*   \\___/   |__|\\_____>\\/\\_/    |____|   |____/ |__|    \\_____>___|  (______/______>\\_____>______>*",
            "*                                                                                                 *",
            "***************************************************************************************************"
    };

    for(int i = 0; i < 8; i++) {
        if (i == 0) {
            cct_setcolor(COLOR_BLACK, COLOR_PINK);
        }
        else if (i == 7) {
            cct_setcolor(COLOR_BLACK, COLOR_PINK);
        }
        else {
            cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
        }

        std::cout << sign[i] << std::endl;
    }
    cct_setcolor();
    cout << "�������û��鿴����׶Σ�" << endl;
    system("pause");
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
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("����");
    flowerShop.addFlowerType("�۹���");
    flowerShop.addFlowerType("������");
    flowerShop.addFlowerType("���޾�");
    flowerShop.addFlowerType("���տ�");
    flowerShop.addFlowerType("���˲�");
    flowerShop.addFlowerType("�ջ�");
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
