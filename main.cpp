#include<iostream>
#include"FrontController/FrontController.h"

#include<string>

using namespace std;



int main()
{

	Dispatcher dispatcher;
	FrontController frontController;
	frontController.set(&dispatcher);
	const string noTestPattern[] = { "frontController", "RAII", "singleton"}; //���ϲ������ģ�?


	for (int i = 0; i < 30; i++)
	{
		bool continueFlag = false;
		for (auto str : noTestPattern) {

			if (designPatterns[i] == str) {
				continueFlag = true;
				break;
			}
		}

		if (continueFlag) {
			continue;
		}



		frontController.dispatchRequest(designPatterns[i]);
		system("pause");
		cout << endl;
	}

	system("pause");

	testAll();
	return 0;
}