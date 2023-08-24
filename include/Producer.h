#pragma once
#include "Locker.h"
#include "Message.h"

class Producer
{
	// static, internal globals :
	static Lockers _lockers;

	// globals (by reference) :
	List<Message>& _global_list;

	// parameters :
	int _millisecondsToWait;

public:
	Producer(List<Message>& global_stack, int millisecondsToWait;

	void operator() ();
};
