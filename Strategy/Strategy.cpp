#include "Strategy.h"

void testStrategy()
{
    Strategy* strategyWinter = new Winter;
    Strategy* strategySpring = new Spring;
    Strategy* strategyTanabata = new Tanabata;
    Strategy* strategysalesPromotion = new salesPromotion;

    Adder add1(100, strategyWinter);
    std::cout << "在冬季购买了原价100元的花束\n";
    add1.Prize();

    std::cout << "\n";
    Adder add2(300, strategyWinter);
    std::cout << "在冬季购买了原价300元的花束\n";
    add2.Prize();

    std::cout << "\n";
    Adder add3(100, strategySpring);
    std::cout << "在春季购买了原价100元的花束\n";
    add3.Prize();

    std::cout << "\n";
    Adder add4(300, strategySpring);
    std::cout << "在春季购买了原价300元的花束\n";
    add4.Prize();

    std::cout << "\n";
    Adder add5(100, strategyTanabata);
    std::cout << "在七夕购买了原价100元的花束\n";
    add5.Prize();

    std::cout << "\n";
    Adder add6(300, strategyTanabata);
    std::cout << "在七夕购买了原价300元的花束\n";
    add6.Prize();

    std::cout << "\n";
    Adder add7(100, strategysalesPromotion);
    std::cout << "在打折时候购买了原价100元的花束\n";
    add7.Prize();

    std::cout << "\n";
    Adder add8(300, strategysalesPromotion);
    std::cout << "在打折时候购买了原价300元的花束\n";
    add8.Prize();
    
    delete strategyWinter;
    delete strategySpring;
    delete strategyTanabata;
    delete strategysalesPromotion;
}