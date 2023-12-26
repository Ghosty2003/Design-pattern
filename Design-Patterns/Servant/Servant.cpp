#include <iostream>
#include<vector>
#include "Servant.h"
using namespace std;


void FloristServant::watering(vector<Flower> flowers) {
	cout << "开始浇水" << endl;
	int len = flowers.size();
	for (int i = 0; i < 3; i++) {
		cout << "浇灌" << flowers[i].getName() << flowers[i].getNums() << "盆" << endl;
	}
	cout << "浇水结束" << endl;
}

void FloristServant::replenishStock(vector<Flower> flowers) {
	cout << "开始管理库存" << endl;
	int len = flowers.size();
	for (int i = 0; i < len; i++) {
		cout <<  flowers[i].getName()<<"的库存: " << flowers[i].getNums() << "盆" << endl;
	}
	cout << "库存管理结束" << endl;
}


void FloristShop::useServant() {
	vector<Flower> flowers;
	
	flowers.push_back(Flower("玫瑰花", 10));
	flowers.push_back(Flower("满天星", 12));
	flowers.push_back(Flower("菊花", 15));

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
