#include<iostream>
#include"FrontController.h"
#include"../utils/cct_tools.h"
#include"../Command/Command.h"
#include"../Builder/Builder.h"
#include"../Bridge/Bridge.h"
#include"../Strategy/Strategy.h"
#include"../Proxy/Proxy.h"
#include"../AbstractFactory/AbstractFactory.h"
#include"../interpreter/interpreter.h"
#include"../objectpool/objectpool.h"
#include"../nullobject/nullobject.h"
#include"../Adapter/Adapter.h"
#include"../Flyweight/Flyweight.h"
#include"../Facade/Facade.h"
#include"../RAII/RAII.h"
#include"../Compose/Compose.h"
using namespace std;

void Dispatcher::dispatch(string request)
{
	if (request == "abstractFactory")
	{
		testAbstractFactory();
	}

	else if (request == "adapter")
	{
		testAdaptor();
	}
	else if (request == "blackBoard")
	{
		//testBlackBoard();
	}
	else if (request == "bridge")
	{
		testBridge();
	}
	else if (request == "builder")
	{
		testBuilder();
	}
	else if (request == "chainOfResponsibility")
	{
		//testChainOfResponsibility();
	}
	else if (request == "command")
	{
		testCommand();
	}
	else if (request == "compose")
	{
		testCompose();
	}
	else if (request == "decorator")
	{
		//testDecorate();
	}
	else if (request == "facade")
	{
		testFacade();
	}
	else if (request == "factoryMethod")
	{
		//testFactoryMethod();
	}
	else if (request == "filter")
	{
		//testFilter();
	}
	else if (request == "flyWeight")
	{
		testFlyweight();
	}
	else if (request == "interpreter")
	{
		test_interpreter();
	}
	else if (request == "iterator")
	{
		//testIterator();
	}
	else if (request == "lazyInitialization")
	{
		//testLazyInitialization();
	}
	else if (request == "mediator")
	{
		//testMediator();
	}
	else if (request == "memento")
	{
		//testMemento();
	}
	else if (request == "nullObject")
	{
		test_nullobject();
	}
	else if (request == "objectPool")
	{
		test_objectpool();
	}
	else if (request == "observer")
	{
		//testObserver();
	}
	else if (request == "prototype")
	{
		//testPrototype();
	}
	else if (request == "proxy")
	{
		testProxy();
	}
	else if (request == "publishSubscribe")
	{
		//testPublishSubscribe();
	}
	else if (request == "servant")
	{
		//testServant();
	}
	else if (request == "state")
	{
		//testState();
	}
	else if (request == "strategy")
	{
		testStrategy();
	}
	else if (request == "templateMethod")
	{
		//testTemplateMethod();
	}
	else if (request == "transferObject")
	{
		//testTransferObject();
	}
	else if (request == "visitor")
	{
		//testVisitor();
	}
}

//
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_HBLUE);
	if (request == "compose") {
		cout << "";
	}
	else if (request == "decorator") {
		cout << "";
	}
	else if (request == "factoryMethod") {
		cout << "";
	}
	else if (request == "filter") {
		cout << "";
	}
	else if (request == "interpreter") {
		cout << "";
	}
	else if (request == "lazyInitialization") {
		cout << "";
	}
	else if (request == "prototype") {
		cout << "";
	}
	else if (request == "strategy") {
		cout << "";
	}
	else if (request == "iterator") {
		cout << "";
	}
	else if (request == "facade") {
		cout << "";
	}
	else if (request == "nullObject") {
		cout << "";
	}
	else if (request == "servant") {
		cout << "";
	}
	else if (request == "adapter") {
		cout << "";
	}
	else if (request == "blackBoard") {
		cout << "";
	}
	else if (request == "bridge") {
		cout << "";
	}
	else if (request == "builder") {
		cout << "";
	}
	else if (request == "chainOfResponsibility") {
		cout << "";
	}
	else if (request == "command") {
		cout << "";
	}
	else if (request == "observer") {
		cout << "";
	}
	else if (request == "flyWeight") {
		cout << "";
	}
	else if (request == "mediator") {
		cout << "";
	}
	else if (request == "memento") {
		cout << "";
	}
	else if (request == "objectPool") {
		cout << "";
	}
	else if (request == "proxy") {
		cout << "";
	}
	else if (request == "state") {
		cout << "";
	}
	else if (request == "templateMethod") {
		cout << "";
	}
	else if (request == "transferObject") {
		cout << "";
	}
	else if (request == "visitor") {
		cout << "";
	}
	else if (request == "abstractFactory") {
		cout << "";
	}
	else if (request == "publishSubscribe") {
		cout << "";
	}

	cct_setcolor();
}

void FrontController::trackRequest(string request)
{
	string originRequest = request;
	if (request == "observer") {
		request += " && singleton";
	}
	else if (request == "memento") {
		request += " && singleton";
	}
	else if (request == "publishSubscribe") {
		request += " && singleton";
	}
	else if (request == "templateMethod") {
		request += " && RAII";
	}
 // 设置花的颜色为亮粉色（亮红色前景，黑色背景）
    cct_setcolor(COLOR_BLACK, COLOR_PINK);

    // 绘制一排花
    for (int i = 0; i <= 15; i++) {
        cout << "  **  ";
    }
    cout<<"\n";
    for (int i = 0; i <= 15; i++) {
         cout << " *  * ";
    }
    cout<<"\n";
    for (int i = 0; i <= 15; i++) {
        cout << "  **  ";
    }
    cout<<"\n";
    // 重置颜色为默认值
    cct_setcolor();
	outputScene(originRequest);
	cout << "\n";

	cct_setcolor(COLOR_BLACK, COLOR_HGREEN);
	cout << "design pattern request:" << request << endl;
	cct_setcolor();
}

void FrontController::set(Dispatcher* d)
{
	dispatcher = d;
}

void FrontController::dispatchRequest(string request)
{
	trackRequest(request);
	dispatcher->dispatch(request);
}

void testAll() {
	while (1) {
		cct_cls();
		for (int i = 0; i < 30; i++) {
			string request = designPatterns[i];
			if (request == "observer") {
				request += " && singleton";
			}
			else if (request == "memento") {
				request += " && singleton";
			}
			else if (request == "publishSubscribe") {
				request += " && singleton";
			}
			else if (request == "templateMethod") {
				request += " && RAII";
			}
			cout << i << "." << request << endl;
		}
		cout << "30.退出\n";
		int index;
		cin >> index;
		if (index == 30) {
			break;
		}
		FrontController frontController;
		frontController.dispatchRequest(designPatterns[index]);
		system("pause");
	}
}
