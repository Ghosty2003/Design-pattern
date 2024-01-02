#pragma once
#include <iostream>
#include <string>

/**
 * ��Ʒ����??
 */
class aya_FlowerBouquet
{
public:
    virtual ~aya_FlowerBouquet() {}
    virtual std::string show() const = 0;
};

/**
 * �������ṩ����ʵ??
 */
class aya_RoseBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "õ�廨";
    }
};

class aya_LilyBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "�ٺϻ�";
    }
};

class aya_TulipBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "������";
    }
};

/**
 * �����ߣ�����
 */
class aya_FlowerShop
{
public:
    virtual ~aya_FlowerShop() {}
    virtual aya_FlowerBouquet *createBouquet(int quantity) const = 0;
    virtual std::string getName() const = 0;

    std::string show(int quantity) const
    {
        // ������������
        aya_FlowerBouquet *bouquet = this->createBouquet(quantity);
        // �����Ʒ
        std::string result = getName() + "�Ƴ�" + std::to_string(quantity) + "" + bouquet->show();
        delete bouquet;
        return result;
    }
};

/**
 * ����Ĵ����ߣ���ͬ���͵Ļ�??
 */
class aya_LuxuryFlowerShop : public aya_FlowerShop
{
public:
    aya_FlowerBouquet *createBouquet(int quantity) const override
    {
        return new aya_RoseBouquet();
    }
    std::string getName() const override
    {
        return "��������";
    }
};

class aya_StandardFlowerShop : public aya_FlowerShop
{
public:
    aya_FlowerBouquet *createBouquet(int quantity) const override
    {
        return new aya_LilyBouquet();
    }
    std::string getName() const override
    {
        return "��׼����";
    }
};

class aya_BudgetFlowerShop : public aya_FlowerShop
{
public:
    aya_FlowerBouquet *createBouquet(int quantity) const override
    {
        return new aya_TulipBouquet();
    }
    std::string getName() const override
    {
        return "���û���";
    }
};

// �ͻ�����֪�������ֻ�??
void FlowerShopClientCode(const aya_FlowerShop &flowerShop, int quantity);
void testFactoryMethod();
