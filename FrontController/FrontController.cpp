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
#include"../FactoryMethod/FactoryMethod.h"
#include"../Prototype/Prototype.h"

#include "../ChainOfResponsibility/ChainOfResponsibility.h"
#include "../Servant/Servant.h"
#include "../TemplateMethod/TemplateMethod.h"
#include"../Lazy/LazyFlowerShop.h"
#include"../PublishSubscribe/PublishSubscribe.h"
#include"../Single/Single.h"
#include"../Iterator/Iterator.h"
#include"../State/State.h"
#include"../Visitor/Visitor.h"
#include"../Facade/Facade.h"
#include"../Compose/Compose.h"

#include"../Interpreter/interpreter.h"
#include"../Objectpool/objectpool.h"
#include"../Nullobject/nullobject.h"
// #include "../Mediator/Mediator.h"
// #include "../TransferObject/TransferObject.h"

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

    // 遍历并打印每一
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

    // 重置为默认颜
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
		testAdaptor();
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
	else if (request == "mediator")
	{
		//testMediator();
	}
	else if (request == "TransferObject")
	{
		//testTransferObject();
	}
	
}


//
void outputScene(string request) {
	cct_setcolor(COLOR_BLACK, COLOR_CYAN);
	if (request == "compose") {
		cout << "组合模式可以用于构建花店产品的层次结构，使得顾客能够以统一的方式查看和购买单一花卉或花束套装.";
	}
	else if (request == "factoryMethod") {
		cout << "抽象工厂生成高端花束工厂和经济型花束工厂两个子工厂，每个子工厂生产对应花束";
	}
	else if (request == "interpreter") {
		cout << "花店老板可以向员工发出购买花束、浇水和运送花束等要求，员工通过解释器执行相关要求";
	}
	else if (request == "lazyInitialization") {
		cout << "用户在初次进入系统时，可以填写默认花束偏好、收货地址及联系方式，可供必要时自动填写";
	}
	else if (request == "prototype") {
		cout << "展示了原型模式。它创建了几种花卉对象，允许通过克隆方法创建它们的副本，然后展示各种花卉的信息。";
	}
	else if (request == "strategy") {
		cout << "使用现存策略进行商品价格制定";
	}
	else if (request == "iterator") {
		cout << "花店有一个花卉库存，通过使用迭代器，客户可以遍历花店的所有花卉种类";
	}
	else if (request == "facade") {
		cout << "外观模式可以被用于简化顾客购物体验，使顾客能够轻松地购买花卉、安排活动或享受送花服务.";
	}
	else if (request == "nullObject") {
		cout << "花店可以雇佣、解雇并让员工工作，花店有员工时能够正常工作，当花店没有员工时，让空员工对象执行默认操作";
	}
	else if (request == "servant") {
		cout << "花店类通过花店员工类来完成花店的工作，如库存的管理、花的浇灌";
	}
	else if (request == "adapter") {
		cout << "在花店场景中处理不同供应商提供的花卉信息。通过适配器，花店可以统一不同供应商的接口，使其能够轻松地展示花卉信息";
	}
	else if (request == "bridge") {
		cout << "对不同对象的商品，通过桥接选择实现形式，包装进不同的花";
	}
	else if (request == "builder") {
		cout << "对每笔订单的整个订单进行过程进行构建";
	}
	else if (request == "chainOfResponsibility") {
		cout << "在花束的销售流程中设计一个责任链来处理不同的模式，如花束的制作、花束的包装和花束的销售。请求将沿责任链传递，直到有一个处理者能处理它为歀";
	}
	else if (request == "command") {
		cout << "线上订购花卉的过程使用命令模式，用于下单，订单接收和订单撤销";
	}
	else if (request == "flyWeight") {
		cout << "可以被运用于优化对于花卉对象的创建和管理，特别是在存在大量相似花卉对象的情况下。如果花店经常处理大量相似的花卉对象，比如相同种类或相同颜色的花朵，那么使用享元模式可以显著减少内存占用";
	}
	else if (request == "objectPool") {
		cout << "顾客前往花店购买花束，顾客到来时从对象池获取顾客对象，顾客离开时将对象返回给对象池";
	}
	else if (request == "proxy") {
		cout << "运货代理运送花束工厂的花束";
	}
	else if (request == "state") {
		cout << "花店内的花卉因为新鲜度的不同而已不同的方式销售或处理，新鲜的花卉以正常的价格出售，稍微有点不新鲜的花卉以折扣价销售，枯萎，品次较差的花卉直接销毁";
	}
	else if (request == "templateMethod") {
		cout << "把花卉的生产定义成一个模板，其中包含选择种子、种植、浇水、施肥。这些具体的步骤可以由不同类的花提供，以适应不同花卉的生长需求";
	}
	else if (request == "visitor") {
		cout << "在该模式中有顾客和员工两类访问者，有花卉和盆栽两类被访问者，不同访问者可以对不同的被访问者进行相应的操作";
	}
	else if (request == "abstractFactory") {
		cout << "抽象工厂生成高端花束工厂和经济型花束工厂两个子工厂，每个子工厂生产对应花";
	}
	else if (request == "publishSubscribe") {
		cout << "库存系统发布更新花束数量，买家收到商店上新花束信息，包括花束种类及数";
	}
	else if (request == "Single") {
		cout << "统计网站上购买的花束数量，显示月销量，类似于网站计数器";
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
