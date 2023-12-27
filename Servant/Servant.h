#pragma once
#include <iostream>
#include<vector>
using namespace std;

class Flower {
private:
	string flowerName;
	int nums;
public:
	Flower(string flowername, int nums) {
		this->flowerName = flowername;
		this->nums = nums;
	}

	Flower() {};

	string getName() {
		return this->flowerName;
	}

	int getNums() {
		return this->nums;
	}
};

class FloristServant {
public:
	void watering(vector<Flower> flowers);	//鲜花浇水

	void replenishStock(vector<Flower> flowers);	//管理鲜花库存

};

class FloristShop {
private:
	FloristServant floristServant;

public:
	FloristShop(const FloristServant& servant) : floristServant(servant) {}

	void useServant();

};

void testServant();