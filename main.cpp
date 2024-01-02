#include<iostream>
#include"FrontController/FrontController.h"

#include<string>

using namespace std;




int main()
{
	displayFloristSign();
	Dispatcher dispatcher;
	FrontController frontController;
	frontController.set(&dispatcher);
	const string noTestPattern[] = { "frontController", "RAII", "singleton"}; 
	int user = 2;//2个之后是user
	int orders = 9; //
	int sells = 14;
	int employees = 20;

	for (int i = 0; i < 23; i++)
	{
		if(i==0){
			material();
		}
		else if(i==user){
			purchase();
		}
		else if(i==orders){
			order();
		}
		else if(i==sells){
			sell();		
		}
		else if(i==employees){
			employee();
		}
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

	testAll();
	return 0;
}