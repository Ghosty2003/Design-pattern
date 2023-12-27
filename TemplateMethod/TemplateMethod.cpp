#include <iostream>
#include"TemplateMethod.h"
using namespace std;

void Rose_wwj::selectSeed() {
	cout << "选择玫瑰种子" << endl;
}

void Rose_wwj::plant() {
	cout << "种植玫瑰" << endl;
}

void Rose_wwj::water() {
	cout << "浇灌玫瑰花" << endl;
}

void Rose_wwj::fertilize() {
	cout << "给玫瑰花施肥" << endl;
}

void Lily_wwj::selectSeed() {
	cout << "选择百合花种子" << endl;
}

void Lily_wwj::plant() {
	cout << "种植百合花" << endl;
}

void Lily_wwj::water() {
	cout << "浇灌百合花" << endl;
}

void Lily_wwj::fertilize() {
	cout << "给百合花施肥" << endl;
}

void testTemplateMethod() {
	Rose_wwj rose;
	Lily_wwj lily;
	cout << "玫瑰花的生产流程：" << endl;
	rose.produceFlower();
	cout << "百合花的生产流程：" << endl;
	lily.produceFlower();

}

//int main() {
//	testTemplateMethod();
//
//	return 0;
//}