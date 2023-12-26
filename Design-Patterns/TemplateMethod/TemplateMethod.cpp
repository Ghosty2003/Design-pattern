#include <iostream>
#include"TemplateMethod.h"
using namespace std;

void Rose::selectSeed() {
	cout << "选择玫瑰种子" << endl;
}

void Rose::plant() {
	cout << "种植玫瑰" << endl;
}

void Rose::water() {
	cout << "浇灌玫瑰花" << endl;
}

void Rose::fertilize() {
	cout << "给玫瑰花施肥" << endl;
}

void Lily::selectSeed() {
	cout << "选择百合花种子" << endl;
}

void Lily::plant() {
	cout << "种植百合花" << endl;
}

void Lily::water() {
	cout << "浇灌百合花" << endl;
}

void Lily::fertilize() {
	cout << "给百合花施肥" << endl;
}

void testTemplateMethod() {
	Rose rose;
	Lily lily;
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