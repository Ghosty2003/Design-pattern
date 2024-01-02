#pragma once
#include<iostream>
using namespace std;

const string designPatterns[25] = {
	"flyWeight", //first
	"templateMethod",//material
	"iterator",//first
	"command", //
	"compose",
	"lazyInitialization",
	"bridge",//
	"objectPool", //
	"publishSubscribe", //user
	"builder",//first
	"facade",//
	"proxy",//
	"adapter",//
	"abstractFactory",//orders
	"state",//first
	"factoryMethod",
	"prototype",
	"strategy",
	"chainOfResponsibility", //seller
	"visitor",//first
	"interpreter",
	"nullObject", //
	"servant", //employee
	"frontController",
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
