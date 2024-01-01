#include "FactoryMethod.h"

void FlowerShopClientCode(const aya_FlowerShop &flowerShop, int quantity)
{
    std::cout << "欢迎光临" << flowerShop.show(quantity) << std::endl;
}

void testFactoryMethod()
{
    std::cout << "购买者1：豪华花店\n";
    aya_FlowerShop *luxuryShop = new aya_LuxuryFlowerShop();
    FlowerShopClientCode(*luxuryShop, 3); // Buying 3 bouquets
    std::cout << std::endl;

    std::cout << "购买者2：标准花店\n";
    aya_FlowerShop *standardShop = new aya_StandardFlowerShop();
    FlowerShopClientCode(*standardShop, 5); // Buying 5 bouquets
    std::cout << std::endl;

    std::cout << "购买者3：经济花店\n";
    aya_FlowerShop *budgetShop = new aya_BudgetFlowerShop();
    FlowerShopClientCode(*budgetShop, 2); // Buying 2 bouquets
    std::cout << std::endl;

    delete luxuryShop;
    delete standardShop;
    delete budgetShop;
}

// int main()
// {
//     testFactoryMethod();
//     return 0;
// }
