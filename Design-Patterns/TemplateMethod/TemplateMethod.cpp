#include <iostream>
#include"TemplateMethod.h"
using namespace std;

void Rose::selectSeed() {
	cout << "ѡ��õ������" << endl;
}

void Rose::plant() {
	cout << "��ֲõ��" << endl;
}

void Rose::water() {
	cout << "����õ�廨" << endl;
}

void Rose::fertilize() {
	cout << "��õ�廨ʩ��" << endl;
}

void Lily::selectSeed() {
	cout << "ѡ��ٺϻ�����" << endl;
}

void Lily::plant() {
	cout << "��ֲ�ٺϻ�" << endl;
}

void Lily::water() {
	cout << "����ٺϻ�" << endl;
}

void Lily::fertilize() {
	cout << "���ٺϻ�ʩ��" << endl;
}

void testTemplateMethod() {
	Rose rose;
	Lily lily;
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