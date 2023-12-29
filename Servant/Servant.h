#pragma once
#include <iostream>
#include<vector>
using namespace std;

class Flower_wwj {
private:
	string flowerName;
	int nums;
public:
	Flower_wwj(string flowername, int nums) {
		this->flowerName = flowername;
		this->nums = nums;
	}

	Flower_wwj() {};

	string getName() {
		return this->flowerName;
	}

	int getNums() {
		return this->nums;
	}
};

class FloristServant_wwj {
public:
	void watering(vector<Flower_wwj> flowers);	//鲜花浇水

	void replenishStock(vector<Flower_wwj> flowers);	//管理鲜花库存

};

class FloristShop_wwj {
private:
	FloristServant_wwj floristServant;

public:
	FloristShop_wwj(const FloristServant_wwj& servant) : floristServant(servant) {}

	void useServant();

};

void testServant();