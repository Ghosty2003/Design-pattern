#include <iostream>
#include "Bridge.h"
#include "../utils/cct_tools.h"

//��ɫ�ľ���ʵ����
void PinkAndWhite::setattribute()
{
    colour = "ɫϵ���۰�ɫɫϵ����";
}

void RedAndYellow::setattribute()
{
    colour = "ɫϵ�����ɫϵ����";
}

//��װ���ʵľ���ʵ����
void Plastic::setattribute()
{
    Material = "��װ���ʣ�ʹ������";
}

void Paper::setattribute()
{
    Material = "��װ���ʣ�ʹ�ð�װֽ";
}

//�������ľ���ʵ����
void carnation::setattribute()
{
    category = "���ģ�ʹ�ÿ���ܰ";
}

void tulip::setattribute()
{
    category = "���ģ�ʹ��������";
}

//ͨ������ʵ������������
void ToMom::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void ToMom::print()
{
    cout << "*һλ�û����˸�ĸ�׵Ļ���*" << endl;
    cct_setcolor(COLOR_BLACK, COLOR_HPINK);
    cout << implementor1->colour << "." << endl;
    cout << implementor2->Material<< endl;//��װ����
    cout << implementor3->category << "." << endl;
    cct_setcolor();
}

//ͨ������ʵ������������
void ToFriends::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void ToFriends::print()
{
    cout << "*һλ�û����˸����ѵĻ���*" << endl;
    cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
    cout << implementor1->colour << "." << endl;
    cout << implementor2->Material<< endl;//��װ����
    cout << implementor3->category << "." << endl;
    cct_setcolor();
}



int testBridge()
{
    Implementor* PinkWhite = new PinkAndWhite;
    Implementor* RedYellow = new RedAndYellow;
    Implementor* usePlastic = new Plastic;
    Implementor* usePaper = new Paper;
    Implementor* useCarnation = new carnation;
    Implementor* useTulip = new tulip;

    bouquet* mom = new ToMom(PinkWhite, usePaper, useCarnation);
    mom->setattribute();
    mom->print();
    cout << endl;


    bouquet* friends = new ToFriends(RedYellow, usePlastic, useTulip);
    friends->setattribute();
    friends->print();
    cout << endl;
    //�ͷ�
    delete friends;
    delete mom;
    delete PinkWhite;
    delete RedYellow;
    delete usePaper;
    delete usePlastic;
    delete useCarnation;
    delete useTulip;

    cout << endl;

    return 0;
}