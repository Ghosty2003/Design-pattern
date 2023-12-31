#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

enum FlowerType
{
    ROSE = 0,
    TULIP,
    DAISY,
    SUNFLOWER, // 新添加的花的类型 - 向日葵
    LILY       // 新添加的花的类型 - 百合
};

class Flower
{
protected:
    string flowerName;
    string color;

public:
    Flower() {}
    Flower(string flowerName)
        : flowerName(flowerName)
    {
    }
    virtual ~Flower() {}
    virtual Flower *Clone() const = 0;
    virtual void Show()
    {
        std::cout << "这朵花叫" + flowerName + "，颜色是" + color << std::endl;
    }
};

class Rose : public Flower
{
public:
    Rose(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    Flower *Clone() const override
    {
        return new Rose(*this);
    }
};

class Tulip : public Flower
{
public:
    Tulip(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    Flower *Clone() const override
    {
        return new Tulip(*this);
    }
};

class Daisy : public Flower
{
public:
    Daisy(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    Flower *Clone() const override
    {
        return new Daisy(*this);
    }
};

class Sunflower : public Flower
{
public:
    Sunflower(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    Flower *Clone() const override
    {
        return new Sunflower(*this);
    }
};

class Lily : public Flower
{
public:
    Lily(string name, string color)
    {
        this->flowerName = name;
        this->color = color;
    }

    Flower *Clone() const override
    {
        return new Lily(*this);
    }
};

class Prototype
{
private:
    std::unordered_map<FlowerType, Flower *, std::hash<int>> prototypes_;

public:
    Prototype()
    {
        prototypes_[FlowerType::ROSE] = new Rose("玫瑰", "红色");
        prototypes_[FlowerType::TULIP] = new Tulip("郁金香", "黄色");
        prototypes_[FlowerType::DAISY] = new Daisy("雏菊", "白色");
        prototypes_[FlowerType::SUNFLOWER] = new Sunflower("向日葵", "黄色");
        prototypes_[FlowerType::LILY] = new Lily("百合", "白色");
    }

    ~Prototype()
    {
        delete prototypes_[FlowerType::ROSE];
        delete prototypes_[FlowerType::TULIP];
        delete prototypes_[FlowerType::DAISY];
        delete prototypes_[FlowerType::SUNFLOWER];
        delete prototypes_[FlowerType::LILY];
    }

    Flower *CreatePrototype(FlowerType type)
    {
        return prototypes_[type]->Clone();
    }
};

void PrototypeClient(Prototype &prototype);
void testPrototype();
