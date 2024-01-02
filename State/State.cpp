#include"State.h"
#include"../utils/cct_tools.h"
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
    cct_cls();
    const char* sign[] = {
        "**************************************************************************************",
		"*  _________      .__              _____                                             *", 
		"* /   _____/____  |  |   ____     /     \\ _____    ____    _________    ____   ____  *",  
		"* \\_____  \\__  \\ |  | _/ __ \\   /  \\ /  \\__  \\  /    \\  / ___\\__  \\ _/ __ \\ / ___\\ *",  
		"* /        \\/ __ \\|  |_\\  ___/  /    Y    \\/ __ \\|   |  \\/ /_/  > __ \\  ___// /_/  >*",  
		"*/_______  (____  /____/\\___  > \\____|__  (____  /___|  /\\___  (____  /\\___  >___  / *",
        "*        \\/     \\/          \\/          \\/     \\/     \\//_____/     \\/     \\/_____/  *",  
		"*                                                                      *",  
		"************************************************************************", 

    };

    for (int i = 0; i < 9; i++) {
		if(i==0){
			cct_setcolor(COLOR_BLACK, COLOR_PINK);
		}
		else if(i==7){
			cct_setcolor(COLOR_BLACK, COLOR_PINK);
		}
		else{
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
		}

        std::cout << sign[i] << std::endl;
    }

    cct_setcolor();
    cout<<"下面是商品销售管理阶段："<<endl;

    FlowerShopxlj1 flowerShop;

    //cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    //std::cout << "���ڲ�ͬ����״̬�Ļ��ܣ�ִ�в�ͬ�Ĵ�����ʽ\n" << endl;
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
