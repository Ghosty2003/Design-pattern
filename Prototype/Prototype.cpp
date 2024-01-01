// #include "Prototype.h"

// void PrototypeClient(Prototype &prototype)
// {
//     std::cout << "欢迎光临花店，我们有以下花卉可供选择：" << std::endl;

//     Flower *flower = prototype.CreatePrototype(FlowerType::ROSE);
//     flower->Show();
//     delete flower;

//     std::cout << "\n";

//     flower = prototype.CreatePrototype(FlowerType::TULIP);
//     flower->Show();
//     delete flower;

//     std::cout << "\n";

//     flower = prototype.CreatePrototype(FlowerType::DAISY);
//     flower->Show();
//     delete flower;

//     std::cout << "\n";

//     flower = prototype.CreatePrototype(FlowerType::SUNFLOWER);
//     flower->Show();
//     delete flower;

//     std::cout << "\n";

//     flower = prototype.CreatePrototype(FlowerType::LILY);
//     flower->Show();
//     delete flower;
// }

// void testPrototype()
// {
//     Prototype *prototype = new Prototype();
//     PrototypeClient(*prototype);
//     delete prototype;
// }

// int main()
// {
//     // 调用测试函数
//     testPrototype();

//     return 0;
// }