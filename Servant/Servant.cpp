#include <iostream>
#include<vector>
#include "Servant.h"
using namespace std;


void FloristServant_wwj::watering(vector<Flower_wwj> flowers) {
	cout << "��ʼ��ˮ" << endl;
	int len = flowers.size();
	for (int i = 0; i < 3; i++) {
		cout << "����" << flowers[i].getName() << flowers[i].getNums() << "��" << endl;
	}
	cout << "��ˮ����" << endl;
}

void FloristServant_wwj::replenishStock(vector<Flower_wwj> flowers) {
	cout << "��ʼ������" << endl;
	int len = flowers.size();
	for (int i = 0; i < len; i++) {
		cout <<  flowers[i].getName()<<"�Ŀ��: " << flowers[i].getNums() << "��" << endl;
	}
	cout << "���������" << endl;
}


void FloristShop_wwj::useServant() {
	vector<Flower_wwj> flowers;
	
	flowers.push_back(Flower_wwj("õ�廨", 10));
	flowers.push_back(Flower_wwj("������", 12));
	flowers.push_back(Flower_wwj("�ջ�", 15));

	floristServant.watering(flowers);
	floristServant.replenishStock(flowers);
}

void testServant() {
	FloristServant_wwj floristServant;
	FloristShop_wwj floristShop(floristServant);

	floristShop.useServant();
}

//int main() {
//	testServant();
//
//	return 0;
//}
