#pragma once
#include <cmath>
#include <iostream>
#include <string>

// 构建价格自动调整器
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::double_t Prize(std::double_t prize) const = 0;
};


class Adder
{
private:
    Strategy* strategy_;
    std::double_t prize;
public:

    Adder(std::double_t startPrize) {
        this->prize = startPrize;
    }

    Adder(std::double_t startPrize, Strategy* strategy) {
        this->prize = startPrize;
        this->setStrategy(strategy);
    }

    //动态修改
    void setStrategy(Strategy* strategy)
    {
        strategy_ = strategy;
    }
    //获得价格的实现
    void Prize() const
    {
        if (strategy_) {
            std::cout << "起始价为" << prize<<std::endl;
            std::double_t result = strategy_->Prize(prize);
            std::cout << "需要支付"<< result << "元\n";
        }
        else {
            std::cout << "暂无策略，采用原本价格\n";
        }
    }
};

class Spring : public Strategy
{
public:
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=1.1;
        if (prize >= 200)//大于200给折扣，9折
        {
            return std::double_t(prize*0.9);
        }
        else
        {
            return std::double_t(prize);
        } 
    }
};
class Winter : public Strategy
{
public:
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=1.2;
        if (prize >= 200)//大于200给折扣，9折
        {
            return std::double_t(prize*0.9);
        }
        else
        {
            return std::double_t(prize);
        } 
    }
};

class Tanabata : public Strategy
{
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=1.3;
        if (prize >= 200)//大于200给折扣，9折
        {
            return std::double_t(prize*0.9);
        }
        else
        {
            return std::double_t(prize);
        } 
    }
};
class salesPromotion : public Strategy//打折
{
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=0.8;
        return std::double_t(prize);
        
    }
};


void testStrategy();