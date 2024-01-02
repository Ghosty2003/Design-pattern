#include"State.h"
#include "../utils/cct_tools.h"
using namespace std;
void drawFreshFlower() {
    std::cout << "   @" << std::endl;
    std::cout << "  @@" << std::endl;
    std::cout << " @@@@" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "  |||" << std::endl;
    std::cout << std::endl;
    cct_setcolor();
}

void drawWitheredFlower() {
    
    std::cout << "  @" << std::endl;
    std::cout << " @@@" << std::endl;
    std::cout << "   |" << std::endl;
    std::cout << "   X" << std::endl;
    std::cout << std::endl;
    cct_setcolor();
}
void testState() {
    FlowerShopxlj1 flowerShop;

    //cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    //std::cout << "���ڲ�ͬ����״̬�Ļ��ܣ�ִ�в�ͬ�Ĵ���ʽ\n" << endl;
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    std::cout << "��ӭ����Stateģʽ\n" << endl;

    system("pause");
    cct_setcolor(COLOR_BLACK, COLOR_HRED);
    
    cout << "�峿����ɹ���һ�����ʻ��ܣ�" << endl;
    drawFreshFlower();
    flowerShop.sellFlower();  // ��ʼ״̬�������ʻ�
    system("pause");
    std::cout << endl;


    
    cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
    std::cout << "�������껨��Ȼû�����۳�ȥ" << endl;
    flowerShop.setState(new SlightlyWitheredFlowerState());
    flowerShop.sellFlower();  // ���ϣ����е㲻���ʵĻ�
    system("pause");
    std::cout << endl;

    
    cct_setcolor(COLOR_BLACK, COLOR_HBLACK);
    std::cout << "�����𽥵��㣬�������껨�Ѿ���������Ҫ" << endl;
    drawWitheredFlower();
    flowerShop.setState(new WitheredFlowerState());
    flowerShop.sellFlower();  // ����ή�Ļ���Ʒ�νϲ�
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
