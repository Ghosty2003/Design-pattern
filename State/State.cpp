#include"State.h"
void testState() {

    FlowerShop1 flowerShop;

    flowerShop.sellFlower();  // ��ʼ״̬�������ʻ�

    flowerShop.setState(new SlightlyWitheredFlowerState());
    flowerShop.sellFlower();  // ���ϣ����е㲻���ʵĻ�

    flowerShop.setState(new WitheredFlowerState());
    flowerShop.sellFlower();  // ����ή�Ļ���Ʒ�νϲ�
}
