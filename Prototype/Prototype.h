#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

enum aya_FlowerType
{
    aya_ROSE = 0,
    aya_TULIP,
    aya_DAISY,
    aya_SUNFLOWER, // 新添加的花的类型 - 向日葵
    aya_LILY       // 新添加的花的类型 - 百合
};

class aya_Flower
{
protected:
    string flowerName;
    string color;

public:
    aya_Flower() {}
    aya_Flower(string flowerName)
        : flowerName(flowerName)
    {
    }
    virtual ~aya_Flower() {}
    virtual aya_Flower *Clone() const = 0;
    virtual void Show()
    {
        std::cout << "这朵花叫" + flowerName + "，颜色是" + color << std::endl;
    }
};

class aya_Rose : public aya_Flower
{
public:
    aya_Rose(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    aya_Flower *Clone() const override
    {
        return new aya_Rose(*this);
    }
};

class aya_Tulip : public aya_Flower
{
public:
    aya_Tulip(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    aya_Flower *Clone() const override
    {
        return new aya_Tulip(*this);
    }
};

class aya_Daisy : public aya_Flower
{
public:
    aya_Daisy(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    aya_Flower *Clone() const override
    {
        return new aya_Daisy(*this);
    }
};

class aya_Sunflower : public aya_Flower
{
public:
    aya_Sunflower(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    aya_Flower *Clone() const override
    {
        return new aya_Sunflower(*this);
    }
};

class aya_Lily : public aya_Flower
{
public:
    aya_Lily(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    aya_Flower *Clone() const override
    {
        return new aya_Lily(*this);
    }
};

class aya_Prototype
{
private:
    std::unordered_map<aya_FlowerType, aya_Flower *, std::hash<int>> prototypes_;

public:
    aya_Prototype()
    {
        prototypes_[aya_FlowerType::aya_ROSE] = new aya_Rose("玫瑰", "红色");
        prototypes_[aya_FlowerType::aya_TULIP] = new aya_Tulip("郁金香", "黄色");
        prototypes_[aya_FlowerType::aya_DAISY] = new aya_Daisy("雏菊", "白色");
        prototypes_[aya_FlowerType::aya_SUNFLOWER] = new aya_Sunflower("向日葵", "黄色");
        prototypes_[aya_FlowerType::aya_LILY] = new aya_Lily("百合", "白色");
    }

    ~aya_Prototype()
    {
        delete prototypes_[aya_FlowerType::aya_ROSE];
        delete prototypes_[aya_FlowerType::aya_TULIP];
        delete prototypes_[aya_FlowerType::aya_DAISY];
        delete prototypes_[aya_FlowerType::aya_SUNFLOWER];
        delete prototypes_[aya_FlowerType::aya_LILY];
    }

    aya_Flower *CreatePrototype(aya_FlowerType type)
    {
        return prototypes_[type]->Clone();
    }
};

void PrototypeClient(aya_Prototype &prototype);
void testPrototype();
