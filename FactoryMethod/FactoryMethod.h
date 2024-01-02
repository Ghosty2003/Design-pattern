#pragma once
#include <iostream>
#include <string>

/**
 * 产品：花??
 */
class aya_FlowerBouquet
{
public:
    virtual ~aya_FlowerBouquet() {}
    virtual std::string show() const = 0;
};

/**
 * 具体类提供具体实??
 */
class aya_RoseBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "玫瑰花";
    }
};

class aya_LilyBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "百合花";
    }
};

class aya_TulipBouquet : public aya_FlowerBouquet
{
public:
    std::string show() const override
    {
        return "郁金香";
    }
};

/**
 * 创建者：花店
 */
class aya_FlowerShop
{
public:
    virtual ~aya_FlowerShop() {}
    virtual aya_FlowerBouquet *createBouquet(int quantity) const = 0;
    virtual std::string getName() const = 0;

    std::string show(int quantity) const
    {
        // 创建工厂方法
        aya_FlowerBouquet *bouquet = this->createBouquet(quantity);
        // 输出产品
        std::string result = getName() + "推出" + std::to_string(quantity) + "" + bouquet->show();
        delete bouquet;
        return result;
    }
};

/**
 * 具体的创造者：不同类型的花??
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
        return "豪华花店";
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
        return "标准花店";
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
        return "经济花店";
    }
};

// 客户并不知道是哪种花??
void FlowerShopClientCode(const aya_FlowerShop &flowerShop, int quantity);
void testFactoryMethod();
