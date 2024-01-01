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
#include"../Iterator/Iterator.h"
#include"../State/State.h"
#include"../Visitor/Visitor.h"
#include"../Facade/Facade.h"
#include"../Compose/Compose.h"

using namespace std;

void displayFloristSign() {

    const char* sign[] = {
        "************************************************************************",
		"*.___        __     __________.__                                      *", 
		"*|   | ____ |  | __ \\______   \\  |   ____  ______ __________   _____   *",  
		"*|   |/    \\|  |/ /  |    |  _/  |  /  _ \\/  ___//  ___/  _ \\ /     \\  *",  
		"*|   |   |  \\    <   |    |   \\  |_(  <_> )___ \\ \\___ (  <_> )  Y Y  \\ *",  
		"*|___|___| _/__|_ \\  |____|_  /____/\\____/____  >____  >____/|__|_|  / *",  
		"*                                                                      *",  
		"************************************************************************", 

    };

    // ��������ӡÿһ��
    for (int i = 0; i < 8; i++) {
		if(i==0){
			cct_setcolor(COLOR_BLACK, COLOR_PINK);
		}
		else if(i==7){
			cct_setcolor(COLOR_BLACK, COLOR_PINK);
		}
		else{
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
		}

        std::cout << sign[i] << std::endl;
    }

    // ����ΪĬ����ɫ
    cct_setcolor();
}

void Dispatcher::dispatch(string request)
{
	if (request == "abstractFactory")
	{
		testAbstractFactory();
	}

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
		testIterator();
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
		//testPrototype();
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
		testState();
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
		testVisitor();
	}
	else if (request == "visitor")
	{
		testSingle();
	}
}


//
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_CYAN);
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
		cout << "�����ϰ������Ա����������������ˮ�����ͻ�����Ҫ��Ա��ͨ��������ִ�����Ҫ��";
	}
	else if (request == "lazyInitialization") {
		cout << "";
	}
	else if (request == "prototype") {
		cout << "";
	}
	else if (request == "strategy") {
		cout << "ʹ���ִ���Խ�����Ʒ�۸��ƶ�";
	}
	else if (request == "iterator") {
		cout << "������һ�����ܿ�棬ͨ��ʹ�õ��������ͻ����Ա�����������л������ࡣ";
	}
	else if (request == "facade") {
		cout << "";
	}
	else if (request == "nullObject") {
		cout << "������Թ�Ӷ����Ͳ���Ա��������������Ա��ʱ�ܹ�����������������û��Ա��ʱ���ÿ�Ա������ִ��Ĭ�ϲ�����";
	}
	else if (request == "servant") {
		cout << "������ͨ������Ա��������ɻ���Ĺ���������Ĺ������Ľ��ࡣ";
	}
	else if (request == "adapter") {
		cout << "�ڻ��곡���д���ͬ��Ӧ���ṩ�Ļ�����Ϣ��ͨ�����������������ͳһ��ͬ��Ӧ�̵Ľӿڣ�ʹ���ܹ����ɵ�չʾ������Ϣ��";
	}
	else if (request == "blackBoard") {
		cout << "";
	}
	else if (request == "bridge") {
		cout << "�Բ�ͬ�������Ʒ��ͨ���Ž�ѡ��ʵ����ʽ����װ����ͬ�Ļ���";
	}
	else if (request == "builder") {
		cout << "��ÿ�ʶ����������������й��̽��й���";
	}
	else if (request == "chainOfResponsibility") {
		cout << "�ڻ������������������һ��������������ͬ��ģʽ���绨���������������İ�װ�ͻ��������ۡ����������������ݣ�ֱ����һ���������ܴ�����Ϊֹ��";
	}
	else if (request == "command") {
		cout << "���϶������ܵĹ���ʹ������ģʽ�������µ����������պͶ���������";
	}
	else if (request == "observer") {
		cout << "";
	}
	else if (request == "flyWeight") {
		cout << "���Ա��������Ż����ڻ��ܶ���Ĵ����͹����ر����ڴ��ڴ������ƻ��ܶ��������¡�������꾭������������ƵĻ��ܶ��󣬱�����ͬ�������ͬ��ɫ�Ļ��䣬��ôʹ����Ԫģʽ�������������ڴ�ռ�á�";
	}
	else if (request == "mediator") {
		cout << "";
	}
	else if (request == "memento") {
		cout << "";
	}
	else if (request == "objectPool") {
		cout << "�˿�ǰ�����깺�������˿͵���ʱ�Ӷ���ػ�ȡ�˿Ͷ��󣬹˿��뿪ʱ�����󷵻ظ�����ء�";
	}
	else if (request == "proxy") {
		cout << "�˻��������ͻ��������Ļ���";
	}
	else if (request == "state") {
		cout << "�����ڵĻ�����Ϊ���ʶȵĲ�ͬ���Ѳ�ͬ�ķ�ʽ���ۻ������ʵĻ����������ļ۸���ۣ���΢�е㲻���ʵĻ������ۿۼ����ۣ���ή��Ʒ�νϲ�Ļ���ֱ�����١�";
	}
	else if (request == "templateMethod") {
		cout << "�ѻ��ܵ����������һ��ģ�壬���а���ѡ�����ӡ���ֲ����ˮ��ʩ�ʡ���Щ����Ĳ�������ɲ�ͬ��Ļ��ṩ������Ӧ��ͬ���ܵ���������";
	}
	else if (request == "transferObject") {
		cout << "";
	}
	else if (request == "visitor") {
		cout << "�ڸ�ģʽ���й˿ͺ�Ա����������ߣ��л��ܺ��������౻�����ߣ���ͬ�����߿��ԶԲ�ͬ�ı������߽�����Ӧ�Ĳ�����";
	}
	else if (request == "abstractFactory") {
		cout << "���󹤳����ɸ߶˻��������;����ͻ������������ӹ�����ÿ���ӹ���������Ӧ����";
	}
	else if (request == "publishSubscribe") {
		cout << "���ϵͳ�������»�������������յ��̵����»�����Ϣ�������������༰����";
	}
	else if (request == "Single") {
		cout << "ͳ����վ�Ϲ���Ļ�����������ʾ����������������վ������";
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
    cct_setcolor(COLOR_BLACK, COLOR_PINK);

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
    cct_setcolor();
	outputScene(originRequest);
	cout << "\n";

	cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
	cout << "Current design pattern:" << request << endl;
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

		int bg_color = 0; 
		int fg_color = 14; 

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
            cct_showch(0, i, '*', bg_color, fg_color, 1);
            cout << " " << i - 1 << "." << request;
            cct_showch(consoleWidth - 1, i, '*', bg_color, fg_color, 1);
			cout << endl;
		}
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
