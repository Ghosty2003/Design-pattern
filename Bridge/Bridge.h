#pragma once
#include <iostream>

using namespace std;

//作为桥接接口的实现类
class Implementor
{
public:
    virtual ~Implementor() {}

    string colour; //花朵颜色
    string Material;//包装材质
    string category; //花朵类别

    virtual void setattribute() = 0;
};

//颜色的具体实现类
class PinkAndWhite : public Implementor
{
    //粉白
public:
    ~PinkAndWhite() {}
    void setattribute();
};

class RedAndYellow : public Implementor
{
    //红黄
public:
    ~RedAndYellow() {}
    void setattribute();
};

//包装材质的具体实现类
class Plastic : public Implementor
{
public:
    ~Plastic() {}
    void setattribute();
};

class Paper : public Implementor
{
public:
    ~Paper() {}
    void setattribute();
};

//花朵类别的具体实现类
class carnation : public Implementor//康乃馨
{
public:
    ~carnation() {}
    void setattribute();
};

class tulip : public Implementor//郁金香
{
public:
    ~tulip() {}
    void setattribute();
};


//花束抽象类
class bouquet
{
public:
    Implementor* implementor1;
    Implementor* implementor2;
    Implementor* implementor3;

    bouquet(Implementor* impl, Implementor* imp2, Implementor* imp3) : implementor1(impl), implementor2(imp2), implementor3(imp3) {}

    virtual ~bouquet() {}

    virtual void setattribute() = 0;
    virtual void print() = 0;
};

//扩展抽象类的接口，包括给母亲，给朋友的不同花束
class ToMom : public bouquet
{
public:
    ~ToMom() {}

    ToMom(Implementor* impl, Implementor* imp2, Implementor* imp3) : bouquet(impl, imp2, imp3) {}

    void setattribute();

    void print();

};

class ToFriends : public bouquet
{
public:
    ~ToFriends() {}

    ToFriends(Implementor* impl, Implementor* imp2, Implementor* imp3) : bouquet(impl, imp2, imp3) {}

    void setattribute();

    void print();

};
int testBridge();