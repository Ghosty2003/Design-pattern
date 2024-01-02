#include "Prototype.h"
#include "../utils/cct_tools.h"
void aya_PrototypeClient(aya_Prototype &prototype)
{
    std::cout << "欢迎光临花店，我们有以下花卉可供选择：" << std::endl;
    cct_setcolor(COLOR_BLACK, COLOR_HRED);
    aya_Flower *flower = prototype.CreatePrototype(aya_FlowerType::aya_ROSE);
    flower->Show();
    delete flower;

    std::cout << "\n";
    cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
    flower = prototype.CreatePrototype(aya_FlowerType::aya_TULIP);
    flower->Show();
    delete flower;

    std::cout << "\n";
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    flower = prototype.CreatePrototype(aya_FlowerType::aya_DAISY);
    flower->Show();
    delete flower;

    std::cout << "\n";
    cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
    flower = prototype.CreatePrototype(aya_FlowerType::aya_SUNFLOWER);
    flower->Show();
    delete flower;

    std::cout << "\n";
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
    flower = prototype.CreatePrototype(aya_FlowerType::aya_LILY);
    flower->Show();
    cct_setcolor();
    delete flower;
}

void testPrototype()
{
    aya_Prototype *prototype = new aya_Prototype();
    aya_PrototypeClient(*prototype);
    delete prototype;
}

void testPrototype();
