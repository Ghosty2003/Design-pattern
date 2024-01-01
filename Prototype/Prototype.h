// #pragma once
// #include <iostream>
// #include <string>
// #include <unordered_map>

// using std::string;

// enum FlowerType
// {
//     ROSE = 0,
//     TULIP,
//     DAISY,
//     SUNFLOWER, // ����ӵĻ������� - ���տ�
//     LILY       // ����ӵĻ������� - �ٺ�
// };

// class Flower
// {
// protected:
//     string flowerName;
//     string color;

// public:
//     Flower() {}
//     Flower(string flowerName)
//         : flowerName(flowerName)
//     {
//     }
//     virtual ~Flower() {}
//     virtual Flower *Clone() const = 0;
//     virtual void Show()
//     {
//         std::cout << "��仨��" + flowerName + "����ɫ��" + color << std::endl;
//     }
// };

// class Rose : public Flower
// {
// public:
//     Rose(string name, string color)
//     {
//         this->flowerName = name;
//         this->color = color;
//     }

//     Flower *Clone() const override
//     {
//         return new Rose(*this);
//     }
// };

// class Tulip : public Flower
// {
// public:
//     Tulip(string name, string color)
//     {
//         this->flowerName = name;
//         this->color = color;
//     }

//     Flower *Clone() const override
//     {
//         return new Tulip(*this);
//     }
// };

// class Daisy : public Flower
// {
// public:
//     Daisy(string name, string color)
//     {
//         this->flowerName = name;
//         this->color = color;
//     }

//     Flower *Clone() const override
//     {
//         return new Daisy(*this);
//     }
// };

// class Sunflower : public Flower
// {
// public:
//     Sunflower(string name, string color)
//     {
//         this->flowerName = name;
//         this->color = color;
//     }

//     Flower *Clone() const override
//     {
//         return new Sunflower(*this);
//     }
// };

// class Lily : public Flower
// {
// public:
//     Lily(string name, string color)
//     {
//         this->flowerName = name;
//         this->color = color;
//     }

//     Flower *Clone() const override
//     {
//         return new Lily(*this);
//     }
// };

// class Prototype
// {
// private:
//     std::unordered_map<FlowerType, Flower *, std::hash<int>> prototypes_;

// public:
//     Prototype()
//     {
//         prototypes_[FlowerType::ROSE] = new Rose("õ��", "��ɫ");
//         prototypes_[FlowerType::TULIP] = new Tulip("������", "��ɫ");
//         prototypes_[FlowerType::DAISY] = new Daisy("����", "��ɫ");
//         prototypes_[FlowerType::SUNFLOWER] = new Sunflower("���տ�", "��ɫ");
//         prototypes_[FlowerType::LILY] = new Lily("�ٺ�", "��ɫ");
//     }

//     ~Prototype()
//     {
//         delete prototypes_[FlowerType::ROSE];
//         delete prototypes_[FlowerType::TULIP];
//         delete prototypes_[FlowerType::DAISY];
//         delete prototypes_[FlowerType::SUNFLOWER];
//         delete prototypes_[FlowerType::LILY];
//     }

//     Flower *CreatePrototype(FlowerType type)
//     {
//         return prototypes_[type]->Clone();
//     }
// };

// void PrototypeClient(Prototype &prototype);
// void testPrototype();