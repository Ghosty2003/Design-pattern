#include <iostream>
#include<vector>
#include "Servant.h"
using namespace std;


void FloristServant_wwj::watering(vector<Flower_wwj> flowers) {
	cout << "开始浇水" << endl;
	int len = flowers.size();
	for (int i = 0; i < 3; i++) {
		cout << "浇灌" << flowers[i].getName() << flowers[i].getNums() << "盆" << endl;
	}
	cout << "浇水结束" << endl;
}

void FloristServant_wwj::replenishStock(vector<Flower_wwj> flowers) {
	cout << "开始管理库存" << endl;
	int len = flowers.size();
	for (int i = 0; i < len; i++) {
		cout <<  flowers[i].getName()<<"的库存: " << flowers[i].getNums() << "盆" << endl;
	}
	cout << "库存管理结束" << endl;
}


void FloristShop_wwj::useServant() {
	vector<Flower_wwj> flowers;
	
	flowers.push_back(Flower_wwj("玫瑰花", 10));
	flowers.push_back(Flower_wwj("满天星", 12));
	flowers.push_back(Flower_wwj("菊花", 15));

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
