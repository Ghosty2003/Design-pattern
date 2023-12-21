#include <iostream>
#include "Bridge.h"


//颜色的具体实现类
void PinkAndWhite::setattribute()
{
    colour = "色系：粉白色色系搭配";
}

void RedAndYellow::setattribute()
{
    colour = "色系：红黄色系搭配";
}

//包装材质的具体实现类
void Plastic::setattribute()
{
    Material = "包装材质：使用塑料";
}

void Paper::setattribute()
{
    Material = "包装材质：使用包装纸";
}

//花朵类别的具体实现类
void carnation::setattribute()
{
    category = "花材：使用康乃馨";
}

void tulip::setattribute()
{
    category = "花材：使用郁金香";
}

//通过具体实现类设置属性
void ToMom::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void ToMom::print()
{
    cout << "*一位用户订了给母亲的花束*" << endl;
    cout << implementor1->colour << "." << endl;
    cout << implementor2->Material<< endl;//包装材质
    cout << implementor3->category << "." << endl;
}

//通过具体实现类设置属性
void ToFriends::setattribute()
{
    implementor1->setattribute();
    implementor2->setattribute();
    implementor3->setattribute();
}

void ToFriends::print()
{
    cout << "*一位用户订了给朋友的花束*" << endl;
    cout << implementor1->colour << "." << endl;
    cout << implementor2->Material<< endl;//包装材质
    cout << implementor3->category << "." << endl;
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