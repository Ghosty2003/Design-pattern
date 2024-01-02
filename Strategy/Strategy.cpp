#include <iostream>
#include "Strategy.h"
#include "../utils/cct_tools.h"
#include "../utils/cct_tools.h"
void testStrategy()
{
    srand(time(0));
    Strategy* strategyWinter = new Winter;
    Strategy* strategySpring = new Spring;
    Strategy* strategyTanabata = new Tanabata;
    Strategy* strategysalesPromotion = new salesPromotion;
    std::cout << "***********************************\n";
    //���ò�ͬ����
    int color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);
    Adder add1(100, strategyWinter);
    std::cout << "* �ڶ���������ԭ��100Ԫ�Ļ���     *\n";
    add1.Prize();

    std::cout << "\n";
    Adder add2(300, strategyWinter);
    color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);    
    std::cout << "* �ڶ���������ԭ��300Ԫ�Ļ���     *\n";
    add2.Prize();

    std::cout << "\n";
    Adder add3(100, strategySpring);
    color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* �ڴ���������ԭ��100Ԫ�Ļ���     *\n";
    add3.Prize();

    std::cout << "\n";
    Adder add4(300, strategySpring);
    color = rand() % 10 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* �ڴ���������ԭ��300Ԫ�Ļ���     *\n";
    add4.Prize();

    std::cout << "\n";
    Adder add5(100, strategyTanabata);
    std::cout << "* ����Ϧ������ԭ��100Ԫ�Ļ���     *\n";
    add5.Prize();

    std::cout << "\n";
    Adder add6(300, strategyTanabata);
    color = rand() % 8 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* ����Ϧ������ԭ��300Ԫ�Ļ���     *\n";
    add6.Prize();

    std::cout << "\n";
    Adder add7(100, strategysalesPromotion);
    color = rand() % 2 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* �ڴ���ʱ������ԭ��100Ԫ�Ļ��� *\n";
    add7.Prize();

    std::cout << "\n";
    Adder add8(300, strategysalesPromotion);
    color = rand() % 5 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* �ڴ���ʱ������ԭ��300Ԫ�Ļ��� *\n";
    add8.Prize();
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    std::cout << "***********************************\n";
    delete strategyWinter;//�ͷŲ���
    delete strategySpring;
    delete strategyTanabata;
    delete strategysalesPromotion;
}