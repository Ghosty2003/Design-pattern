#pragma once
#include<iostream>
using namespace std;

const string designPatterns[25] = {
	"adapter",//first
	"templateMethod",//material
	"iterator",//first
	"publishSubscribe",
	"objectPool", 
	"compose",
	"command", //
	"lazyInitialization",
	"bridge",//user
	"builder",//first
	"facade",//
	"proxy",//
	"abstractFactory",//orders
	"factoryMethod",	//first
	"prototype",
	"flyWeight",
	"single",
	"strategy",
	"state",
	"chainOfResponsibility", //seller
	"visitor",//first
	"servant", 
	"interpreter",
	"nullObject", //employee
};
//, "privateClassData";

class Dispatcher
{
public:
	Dispatcher() {}

	void dispatch(string request);
};

class FrontController
{
private:
	Dispatcher* dispatcher;

	void trackRequest(string request);
public:
	FrontController() : dispatcher() {}

	void set(Dispatcher* d);

	void dispatchRequest(string request);
};

void testAll();
void displayFloristSign();
void material();
void purchase();
void order();
void sell();
void employee();