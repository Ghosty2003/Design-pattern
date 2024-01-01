#include<iostream>
#include"FrontController.h"
#include"../utils/cct_tools.h"
// #include"../Command/Command.h"
#include"../Builder/Builder.h"
#include"../Bridge/Bridge.h"
#include"../Strategy/Strategy.h"
#include"../Proxy/Proxy.h"
#include"../AbstractFactory/AbstractFactory.h"
#include"../Adapter/Adapter.h"
#include"../Flyweight/Flyweight.h"

#include"../FactoryMethod/FactoryMethod.h"
#include"../Prototype/Prototype.h"

#include "../ChainOfResponsibility/ChainOfResponsibility.h"
#include "../Servant/Servant.h"
#include "../TemplateMethod/TemplateMethod.h"
//#include "../Prototype/Prototype.h"
#include"../Lazy/LazyFlowerShop.h"
#include"../PublishSubscribe/PublishSubscribe.h"
#include"../Single/Single.h"

using namespace std;

void Dispatcher::dispatch(string request)
{
	// if (request == "abstractFactory")
	// {
	// 	testAbstractFactory();
	// }

	// else
	 if (request == "adapter")
	{
		// testAdaptor();
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
		testChainOfResponsibility();
	}
	// else if (request == "command")
	// {
	// 	testCommand();
	// }
	else if (request == "compose")
	{
		//testCompose();
	}
	else if (request == "decorator")
	{
		//testDecorate();
	}
	else if (request == "facade")
	{
		//testFacade();
	}
	else if (request == "factoryMethod")
	{
		testFactoryMethod();
	}
	else if (request == "filter")
	{
		//testFilter();
	}
	else if (request == "flyWeight")
	{
		// testFlyweight();
	}
	else if (request == "interpreter")
	{
		//test_interpreter();
	}
	else if (request == "iterator")
	{
		//testIterator();
	}
	else if (request == "lazyInitialization")
	{
		testLazyInitialization();
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
		//test_nullobject();
	}
	else if (request == "objectPool")
	{
		//test_objectpool();
	}
	else if (request == "observer")
	{
		//testObserver();
	}
	else if (request == "prototype")
	{
		testPrototype();
	}
	else if (request == "proxy")
	{
		//testAbstractFactory();
	}
	else if (request == "publishSubscribe")
	{
		testPublishSubscribe();
	}
	else if (request == "servant")
	{
		testServant();
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
		testTemplateMethod();
	}
	else if (request == "transferObject")
	{
		//testTransferObject();
	}
	else if (request == "visitor")
	{
		//testVisitor();
	}
	else if (request == "visitor")
	{
		testSingle();
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
	else if (request == "Single") {
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
 // è®¾ç½®èŠ±çš„é¢œè‰²ä¸ºäº®ç²‰è‰²ï¼ˆäº®çº¢è‰²å‰æ™¯ï¼Œé»‘è‰²èƒŒæ™¯ï¼‰
    cct_setcolor(COLOR_BLACK, COLOR_PINK);

    // ç»˜åˆ¶ä¸€æŽ’èŠ±
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
    // é‡ç½®é¢œè‰²ä¸ºé»˜è®¤ï¿½?
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
		
		const int consoleWidth = 80;
		const int consoleHeight = 32;

		int bg_color = 0; // èƒŒæ™¯é¢œè‰²ä»£ç ï¼Œä¾‹å¦‚é»‘è‰?
		int fg_color = 14; // å‰æ™¯é¢œè‰²ä»£ç ï¼Œä¾‹å¦‚é»„è‰?

		// ç»˜åˆ¶é¡¶éƒ¨è¾¹æ¡†
		cct_showch(0, 0, '*', bg_color, fg_color, consoleWidth);
		cout << endl;
		for (int i = 1; i <= 30; i++) {
			string request = (i == 30) ? "quit" : designPatterns[i - 1];
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
			// ç»˜åˆ¶å·¦è¾¹æ¡?
            cct_showch(0, i, '*', bg_color, fg_color, 1);
            cout << " " << i - 1 << "." << request;
            // ç»˜åˆ¶å³è¾¹æ¡?
            cct_showch(consoleWidth - 1, i, '*', bg_color, fg_color, 1);
			cout << endl;
		}
		// ç»˜åˆ¶åº•éƒ¨è¾¹æ¡†
    	cct_showch(0, consoleHeight - 1, '*', bg_color, fg_color, consoleWidth);
		cct_setcolor();
		int index;
		cout << endl;
		cin >> index;
		if (index == 30) {
			break;
		}
		FrontController frontController;
		frontController.dispatchRequest(designPatterns[index]);
		system("pause");
	}
}
