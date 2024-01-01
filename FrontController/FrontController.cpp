#include<iostream>
#include"FrontController.h"
#include"../utils/cct_tools.h"
#include"../Command/Command.h"
#include"../Builder/Builder.h"
#include"../Bridge/Bridge.h"
#include"../Strategy/Strategy.h"
#include"../Proxy/Proxy.h"
#include"../AbstractFactory/AbstractFactory.h"
#include"../Adapter/Adapter.h"
#include"../Flyweight/Flyweight.h"
//#include "../Adapter/Adapter.h"
#include"../FactoryMethod/FactoryMethod.h"
#include"../Prototype/Prototype.h"

#include "../ChainOfResponsibility/ChainOfResponsibility.h"
#include "../Servant/Servant.h"
#include "../TemplateMethod/TemplateMethod.h"
#include"../Lazy/LazyFlowerShop.h"
#include"../PublishSubscribe/PublishSubscribe.h"
#include"../Single/Single.h"

#include"../Mediator/Mediator.h"
#include"../TransferObject/TransferObject.h"

#include"../Iterator/Iterator.h"
#include"../State/State.h"
#include"../Visitor/Visitor.h"
#include"../Facade/Facade.h"
#include"../Compose/Compose.h"

#include"../Interpreter/interpreter.h"
#include"../Objectpool/objectpool.h"
#include"../Nullobject/nullobject.h"


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

    // ��������ӡÿһ
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

    // ����ΪĬ����
    cct_setcolor();
}

void Dispatcher::dispatch(string request)
{
	if (request == "abstractFactory")
	{
		testAbstractFactory();
	}

	// else
	else if (request == "adapter")
	{
		//testAdaptor();
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
	else if (request == "command")
	{
		testCommand();
	}
	else if (request == "compose")
	{
		testCompose();
	}
	else if (request == "facade")
	{
		testFacade();
	}
	else if (request == "factoryMethod")
	{
		testFactoryMethod();
	}
	else if (request == "interpreter")
	{
		test_interpreter();
	}
	else if (request == "iterator")
	{
		testIterator();
	}
	else if (request == "lazyInitialization")
	{
		testLazyInitialization();
	}
	else if (request == "nullObject")
	{
		test_nullobject();
	}
	else if (request == "objectPool")
	{
		test_objectpool();
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
	else if (request == "visitor")
	{
		testVisitor();
	}
	else if (request == "single")
	{
		testSingle();
	}
	else if (request == "flyWeight")
	{
		testFlyweight();
	}
}


//
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_CYAN);
	if (request == "compose") {
		cout << "���ģʽ�������ڹ��������Ʒ�Ĳ�νṹ��ʹ�ù˿��ܹ���ͳһ�ķ�ʽ�鿴�͹���һ���ܻ�����װ.";
	}
	else if (request == "factoryMethod") {
		cout << "���󹤳����ɸ߶˻��������;����ͻ������������ӹ�����ÿ���ӹ���������Ӧ����";
	}
	else if (request == "interpreter") {
		cout << "�����ϰ������Ա����������������ˮ�����ͻ�����Ҫ��Ա��ͨ��������ִ�����Ҫ��";
	}
	else if (request == "lazyInitialization") {
		cout << "�û��ڳ��ν���ϵͳʱ��������дĬ�ϻ���ƫ�á��ջ���ַ����ϵ��ʽ���ɹ���Ҫʱ�Զ���д";
	}
	else if (request == "prototype") {
		cout << "չʾ��ԭ��ģʽ���������˼��ֻ��ܶ�������ͨ����¡�����������ǵĸ�����Ȼ��չʾ���ֻ��ܵ���Ϣ��";
	}
	else if (request == "strategy") {
		cout << "ʹ���ִ���Խ�����Ʒ�۸��ƶ�";
	}
	else if (request == "iterator") {
		cout << "������һ�����ܿ�棬ͨ��ʹ�õ��������ͻ����Ա�����������л�������";
	}
	else if (request == "facade") {
		cout << "���ģʽ���Ա����ڼ򻯹˿͹������飬ʹ�˿��ܹ����ɵع��򻨻ܡ����Ż�������ͻ�����.";
	}
	else if (request == "nullObject") {
		cout << "������Թ�Ӷ����Ͳ���Ա��������������Ա��ʱ�ܹ�����������������û��Ա��ʱ���ÿ�Ա������ִ��Ĭ�ϲ���";
	}
	else if (request == "servant") {
		cout << "������ͨ������Ա��������ɻ���Ĺ���������Ĺ��������Ľ���";
	}
	else if (request == "adapter") {
		cout << "�ڻ��곡���д�����ͬ��Ӧ���ṩ�Ļ�����Ϣ��ͨ�����������������ͳһ��ͬ��Ӧ�̵Ľӿڣ�ʹ���ܹ����ɵ�չʾ������Ϣ";
	}
	else if (request == "bridge") {
		cout << "�Բ�ͬ�������Ʒ��ͨ���Ž�ѡ��ʵ����ʽ����װ����ͬ�Ļ�";
	}
	else if (request == "builder") {
		cout << "��ÿ�ʶ����������������й��̽��й���";
	}
	else if (request == "chainOfResponsibility") {
		cout << "�ڻ������������������һ����������������ͬ��ģʽ���绨���������������İ�װ�ͻ��������ۡ����������������ݣ�ֱ����һ���������ܴ�����Ϊ�L";
	}
	else if (request == "command") {
		cout << "���϶������ܵĹ���ʹ������ģʽ�������µ����������պͶ�������";
	}
	else if (request == "flyWeight") {
		cout << "���Ա��������Ż����ڻ��ܶ���Ĵ����͹������ر����ڴ��ڴ������ƻ��ܶ��������¡�������꾭�������������ƵĻ��ܶ��󣬱�����ͬ�������ͬ��ɫ�Ļ��䣬��ôʹ����Ԫģʽ�������������ڴ�ռ��";
	}
	else if (request == "objectPool") {
		cout << "�˿�ǰ�����깺�������˿͵���ʱ�Ӷ���ػ�ȡ�˿Ͷ��󣬹˿��뿪ʱ�����󷵻ظ������";
	}
	else if (request == "proxy") {
		cout << "�˻��������ͻ��������Ļ���";
	}
	else if (request == "state") {
		cout << "�����ڵĻ�����Ϊ���ʶȵĲ�ͬ���Ѳ�ͬ�ķ�ʽ���ۻ��������ʵĻ����������ļ۸���ۣ���΢�е㲻���ʵĻ������ۿۼ����ۣ���ή��Ʒ�νϲ�Ļ���ֱ������";
	}
	else if (request == "templateMethod") {
		cout << "把花卉的生产定义成一个模板，其中包含选择种子、种植、浇水、施肥。这些具体的步骤可以由不同类的花提供，以适应不同花卉的生长需求。";

	}
	else if (request == "visitor") {
		cout << "�ڸ�ģʽ���й˿ͺ�Ա����������ߣ��л��ܺ��������౻�����ߣ���ͬ�����߿��ԶԲ�ͬ�ı������߽�����Ӧ�Ĳ���";
	}
	else if (request == "abstractFactory") {
		cout << "���󹤳����ɸ߶˻��������;����ͻ������������ӹ�����ÿ���ӹ���������Ӧ��";
	}
	else if (request == "publishSubscribe") {
		cout << "���ϵͳ�������»�������������յ��̵����»�����Ϣ�������������༰��";
	}
	else if (request == "Single") {
		cout << "ͳ����վ�Ϲ���Ļ�����������ʾ����������������վ������";
	}

	cct_setcolor();
}

void FrontController::trackRequest(string request)
{
	string originRequest = request;
	if (request == "AbstractFactory") {
		request += " && proxy";
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
		const int consoleHeight = 27;

		int bg_color = 0; 
		int fg_color = 14; 

		cct_showch(0, 0, '*', bg_color, fg_color, consoleWidth);
		cout << endl;
		for (int i = 1; i <= 25; i++) {
			string request = (i == 25) ? "quit" : designPatterns[i - 1];
			if (request == "AbstractFactory") {
				request += " && proxy";
			}
            cct_showch(0, i, '*', bg_color, fg_color, 1);
            cout << " " << i << "." << request;
            cct_showch(consoleWidth - 1, i, '*', bg_color, fg_color, 1);
			cout << endl;
		}
    	cct_showch(0, consoleHeight - 1, '*', bg_color, fg_color, consoleWidth);
		cct_setcolor();
		int index;
		cout << endl;
		cin >> index;
		if (index == 25) {
			break;
		}
		FrontController frontController;
		frontController.dispatchRequest(designPatterns[index-1]);
		system("pause");
	}
}
