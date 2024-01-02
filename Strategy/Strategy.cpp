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
    //采用不同策略
    int color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);
    Adder add1(100, strategyWinter);
    std::cout << "* 在冬季购买了原价100元的花束     *\n";
    add1.Prize();

    std::cout << "\n";
    Adder add2(300, strategyWinter);
    color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);    
    std::cout << "* 在冬季购买了原价300元的花束     *\n";
    add2.Prize();

    std::cout << "\n";
    Adder add3(100, strategySpring);
    color = rand() % 15 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* 在春季购买了原价100元的花束     *\n";
    add3.Prize();

    std::cout << "\n";
    Adder add4(300, strategySpring);
    color = rand() % 10 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* 在春季购买了原价300元的花束     *\n";
    add4.Prize();

    std::cout << "\n";
    Adder add5(100, strategyTanabata);
    std::cout << "* 在七夕购买了原价100元的花束     *\n";
    add5.Prize();

    std::cout << "\n";
    Adder add6(300, strategyTanabata);
    color = rand() % 8 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* 在七夕购买了原价300元的花束     *\n";
    add6.Prize();

    std::cout << "\n";
    Adder add7(100, strategysalesPromotion);
    color = rand() % 2 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* 在打折时候购买了原价100元的花束 *\n";
    add7.Prize();

    std::cout << "\n";
    Adder add8(300, strategysalesPromotion);
    color = rand() % 5 + 1;
    cct_setcolor(COLOR_BLACK, color);
    std::cout << "* 在打折时候购买了原价300元的花束 *\n";
    add8.Prize();
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    std::cout << "***********************************\n";
    delete strategyWinter;//释放策略
    delete strategySpring;
    delete strategyTanabata;
    delete strategysalesPromotion;
}