#pragma once
#include "Locker.h"
#include <list>
#include "Message.h"


#define NUM_PRODUCERS 2

/// <summary>
///This file defines the Consumer class, which represents a consumer in a multi - threaded producer - consumer scenario.
/// </summary>
class Consumer
{
	///reference to a list of messages
	std::list<Message>& _messages;
	Locker _locker;
public:

	/// <summary>
	/// Constructs a Consumer instance with a reference to a list of messages
	/// </summary>
	/// <param name="messages">reference to a list of messages</param>
	Consumer(std::list<Message>& messages);

	/// <summary>
	///Overloaded function call operator for the Consumer class.
	///This function is intended to be run in a separate threadand performs the message consumption.
	/// </summary>
	void operator()();
};
