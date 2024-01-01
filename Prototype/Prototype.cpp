
#include "Prototype.h"

void aya_PrototypeClient(aya_Prototype &prototype)
{
    std::cout << "娆㈣繋鍏変复鑺卞簵锛屾垜浠湁浠ヤ笅鑺卞崏鍙緵閫夋嫨锛�" << std::endl;

    aya_Flower *flower = prototype.CreatePrototype(aya_FlowerType::aya_ROSE);
    flower->Show();
    delete flower;

    std::cout << "\n";

    flower = prototype.CreatePrototype(aya_FlowerType::aya_TULIP);
    flower->Show();
    delete flower;

    std::cout << "\n";

    flower = prototype.CreatePrototype(aya_FlowerType::aya_DAISY);
    flower->Show();
    delete flower;

    std::cout << "\n";

    flower = prototype.CreatePrototype(aya_FlowerType::aya_SUNFLOWER);
    flower->Show();
    delete flower;

    std::cout << "\n";

    flower = prototype.CreatePrototype(aya_FlowerType::aya_LILY);
    flower->Show();
    delete flower;
}

void testPrototype()
{
    aya_Prototype *prototype = new aya_Prototype();
    aya_PrototypeClient(*prototype);
    delete prototype;
}

// int main()
// {
//     // 璋冪敤娴嬭瘯鍑芥暟
//     testPrototype();

//     return 0;
// }

