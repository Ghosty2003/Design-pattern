#include <iostream>
#include<vector>
#include "Servant.h"
using namespace std;


void FloristServant::watering(vector<Flower> flowers) {
	cout << "��ʼ��ˮ" << endl;
	int len = flowers.size();
	for (int i = 0; i < 3; i++) {
		cout << "����" << flowers[i].getName() << flowers[i].getNums() << "��" << endl;
	}
	cout << "��ˮ����" << endl;
}

void FloristServant::replenishStock(vector<Flower> flowers) {
	cout << "��ʼ������" << endl;
	int len = flowers.size();
	for (int i = 0; i < len; i++) {
		cout <<  flowers[i].getName()<<"�Ŀ��: " << flowers[i].getNums() << "��" << endl;
	}
	cout << "���������" << endl;
}


void FloristShop::useServant() {
	vector<Flower> flowers;
	
	flowers.push_back(Flower("õ�廨", 10));
	flowers.push_back(Flower("������", 12));
	flowers.push_back(Flower("�ջ�", 15));

	floristServant.watering(flowers);
	floristServant.replenishStock(flowers);
}

void testServant() {
	FloristServant floristServant;
	FloristShop floristShop(floristServant);

	floristShop.useServant();
}

int main() {
	testServant();

	return 0;
}
