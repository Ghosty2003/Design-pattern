#include"visitor.h"

void  testVisitor() {
    // 创建花店中的不同花卉
    FreshFlower freshFlower;
    PottedPlant pottedPlant;

    // 将花卉放入集合中
    std::vector<FlowerElement*> flowers;
    flowers.push_back(&freshFlower);
    flowers.push_back(&pottedPlant);

    // 创建营销访问者
    MarketingVisitor marketingVisitor;
    CustomerVisitor customerVisitor;
    // 让访问者访问每个花卉
    std::cout << "Visitor Pattern" << std::endl;
    for (FlowerElement* flower : flowers) {
        flower->accept(marketingVisitor);
        flower->accept(customerVisitor);
        std::cout << std::endl;
    }
}