#pragma once
#include <cmath>
#include <iostream>
#include <string>

// �����۸��Զ�������
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

    //��̬�޸�
    void setStrategy(Strategy* strategy)
    {
        strategy_ = strategy;
    }
    //��ü۸��ʵ��
    void Prize() const
    {
        if (strategy_) {
            std::cout << "��ʼ��Ϊ" << prize<<std::endl;
            std::double_t result = strategy_->Prize(prize);
            std::cout << "��Ҫ֧��"<< result << "Ԫ\n";
        }
        else {
            std::cout << "���޲��ԣ�����ԭ���۸�\n";
        }
    }
};

class Spring : public Strategy
{
public:
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=1.1;
        if (prize >= 200)//����200���ۿۣ�9��
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
        if (prize >= 200)//����200���ۿۣ�9��
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
        if (prize >= 200)//����200���ۿۣ�9��
        {
            return std::double_t(prize*0.9);
        }
        else
        {
            return std::double_t(prize);
        } 
    }
};
class salesPromotion : public Strategy//����
{
    std::double_t Prize(std::double_t prize) const override
    {
        prize*=0.8;
        return std::double_t(prize);
        
    }
};


void testStrategy();