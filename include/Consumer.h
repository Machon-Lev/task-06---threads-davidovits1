#pragma once
#include "Locker.h"
#include <list>
#include "Message.h"


#define NUM_PRODUCERS 2
#define MAX_MILLISECOND 1000

class Consumer
{
	std::list<Message>& _messages;
	Locker _locker;
public:

	Consumer(std::list<Message>& messages);

	void operator()();
};
