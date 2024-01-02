#include"visitor.h"
#include "../utils/cct_tools.h"
void testVisitor() {
    srand(time(0));

    // ���������еĲ�ͬ����
    FreshFlower freshFlower;
    PottedPlant pottedPlant;

    // �����ܷ��뼯����
    std::vector<FlowerElement*> flowers;
    flowers.push_back(&freshFlower);
    flowers.push_back(&pottedPlant);

    // ����Ӫ��������
    MarketingVisitor marketingVisitor;
    CustomerVisitor customerVisitor;
    // �÷����߷���ÿ������
    std::cout << "Visitor Pattern" << std::endl;
    for (FlowerElement* flower : flowers) {
        flower->accept(marketingVisitor);
        flower->accept(customerVisitor);
        std::cout << std::endl;
    }
}