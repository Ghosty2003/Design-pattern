#include <iostream>
#include"TemplateMethod.h"
using namespace std;

void Rose_wwj::selectSeed() {
	cout << "ѡ��õ������" << endl;
}

void Rose_wwj::plant() {
	cout << "��ֲõ��" << endl;
}

void Rose_wwj::water() {
	cout << "����õ�廨" << endl;
}

void Rose_wwj::fertilize() {
	cout << "��õ�廨ʩ��" << endl;
}

void Lily_wwj::selectSeed() {
	cout << "ѡ��ٺϻ�����" << endl;
}

void Lily_wwj::plant() {
	cout << "��ֲ�ٺϻ�" << endl;
}

void Lily_wwj::water() {
	cout << "����ٺϻ�" << endl;
}

void Lily_wwj::fertilize() {
	cout << "���ٺϻ�ʩ��" << endl;
}

void testTemplateMethod() {
	Rose_wwj rose;
	Lily_wwj lily;
	cout << "õ�廨���������̣�" << endl;
	rose.produceFlower();
	cout << "�ٺϻ����������̣�" << endl;
	lily.produceFlower();

}

//int main() {
//	testTemplateMethod();
//
//	return 0;
//}