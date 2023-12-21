#pragma once
#include <iostream>

using namespace std;

//��Ϊ�Žӽӿڵ�ʵ����
class Implementor
{
public:
    virtual ~Implementor() {}

    string colour; //������ɫ
    string Material;//��װ����
    string category; //�������

    virtual void setattribute() = 0;
};

//��ɫ�ľ���ʵ����
class PinkAndWhite : public Implementor
{
    //�۰�
public:
    ~PinkAndWhite() {}
    void setattribute();
};

class RedAndYellow : public Implementor
{
    //���
public:
    ~RedAndYellow() {}
    void setattribute();
};

//��װ���ʵľ���ʵ����
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

//�������ľ���ʵ����
class carnation : public Implementor//����ܰ
{
public:
    ~carnation() {}
    void setattribute();
};

class tulip : public Implementor//������
{
public:
    ~tulip() {}
    void setattribute();
};


//����������
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

//��չ������Ľӿڣ�������ĸ�ף������ѵĲ�ͬ����
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