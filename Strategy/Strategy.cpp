#include "Strategy.h"

void testStrategy()
{
    Strategy* strategyWinter = new Winter;
    Strategy* strategySpring = new Spring;
    Strategy* strategyTanabata = new Tanabata;
    Strategy* strategysalesPromotion = new salesPromotion;

    Adder add1(100, strategyWinter);
    std::cout << "�ڶ���������ԭ��100Ԫ�Ļ���\n";
    add1.Prize();

    std::cout << "\n";
    Adder add2(300, strategyWinter);
    std::cout << "�ڶ���������ԭ��300Ԫ�Ļ���\n";
    add2.Prize();

    std::cout << "\n";
    Adder add3(100, strategySpring);
    std::cout << "�ڴ���������ԭ��100Ԫ�Ļ���\n";
    add3.Prize();

    std::cout << "\n";
    Adder add4(300, strategySpring);
    std::cout << "�ڴ���������ԭ��300Ԫ�Ļ���\n";
    add4.Prize();

    std::cout << "\n";
    Adder add5(100, strategyTanabata);
    std::cout << "����Ϧ������ԭ��100Ԫ�Ļ���\n";
    add5.Prize();

    std::cout << "\n";
    Adder add6(300, strategyTanabata);
    std::cout << "����Ϧ������ԭ��300Ԫ�Ļ���\n";
    add6.Prize();

    std::cout << "\n";
    Adder add7(100, strategysalesPromotion);
    std::cout << "�ڴ���ʱ������ԭ��100Ԫ�Ļ���\n";
    add7.Prize();

    std::cout << "\n";
    Adder add8(300, strategysalesPromotion);
    std::cout << "�ڴ���ʱ������ԭ��300Ԫ�Ļ���\n";
    add8.Prize();
    
    delete strategyWinter;
    delete strategySpring;
    delete strategyTanabata;
    delete strategysalesPromotion;
}