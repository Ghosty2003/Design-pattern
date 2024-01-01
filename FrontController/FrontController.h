#pragma once
#include<iostream>
using namespace std;

const string designPatterns[33] = {

	"compose",
	"decorator",
	"factoryMethod",
	"filter",
	"interpreter",
	"lazyInitialization",
	"prototype",
	"strategy",
	"iterator",//
	"facade",//
	"nullObject", //
	"servant", //
	"adapter",//
	"blackBoard", //
	"bridge",//
	"builder",//
	"chainOfResponsibility", //
	"command", //
	"observer",//(Observer)
	"flyWeight", //
	"mediator",//(Mediator)
	"memento",  //
	"objectPool", //
	"proxy",//
	"state",//
	"templateMethod",//
	"transferObject",//
	"visitor",//
	"abstractFactory",  //
	"publishSubscribe", //(Subscriber)(Channel)(Publisher)
	"frontController",
	"RAII",  //
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
