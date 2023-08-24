#pragma once
#include "Locker.h"
#include "Message.h"
#include <list>

/// <summary>
/// The Producer class represents a producer that generates and adds messages to a global list.
/// </summary>
class Producer
{
	static Locker _locker;          // Static locker for synchronization
	std::list<Message>& _global_list; // Reference to the global list of messages
	int _millisecondsToWait;         // Time interval to wait between producing messages

public:

	/// <summary>
	/// Constructs a Producer instance with a reference to a global list and a waiting time.
	/// </summary>
	/// <param name="global_list">A reference to the global list to which messages will be added</param>
	/// <param name="millisecondsToWait">The time in milliseconds to wait between producing messages</param>
	Producer(std::list<Message>& global_list, int millisecondsToWait);

	/// <summary>
	///Overloaded function call operator for the Producer class.
	///This function is intended to be run in a separate threadand produces messages.
	/// </summary>
	void operator()();
};
