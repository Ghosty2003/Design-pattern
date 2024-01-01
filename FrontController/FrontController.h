#pragma once
#include<iostream>
using namespace std;

const string designPatterns[25] = {

	"compose",
	"factoryMethod",
	"interpreter",
	"lazyInitialization",
	"prototype",
	"strategy",
	"iterator",//
	"facade",//
	"nullObject", //
	"servant", //
	"adapter",//
	"bridge",//
	"builder",//
	"chainOfResponsibility", //
	"command", //
	"flyWeight", //
	"objectPool", //
	"proxy",//
	"state",//
	"templateMethod",//
	"visitor",//
	"abstractFactory",  //
	"publishSubscribe", //(Subscriber)(Channel)(Publisher)
	"frontController",
	"single" //
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
