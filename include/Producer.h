#pragma once
#include "Locker.h"
#include "Message.h"
#include <list>

class Producer
{
	// static, internal globals :
	static Locker _locker;

	// globals (by reference) :
	std::list<Message>& _global_list;

	// parameters :
	int _millisecondsToWait;

public:
	Producer(std::list<Message>& global_stack, int millisecondsToWait);

	void operator() ();
};
