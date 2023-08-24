#include "Producer.h"
#include <iostream>

// init static : 
Locker Producer::_locker;

// functions :
Producer::Producer(std::list<Message>& global_list, int millisecondsToWait) :
	_global_list(global_list),
	_millisecondsToWait(millisecondsToWait){}

void Producer::operator()()
{
	Message msg;
	msg.val = static_cast<double>(msg.size_tid = std::hash<std::thread::id>{}(std::this_thread::get_id()));
	msg.is_finish = false;
	try
	{
		while (true)
		{
			{
				std::lock_guard lck(_locker.mtx_msg);
				_global_list.push_back(msg);
			}
			_locker.cond_msg.notify_all();
			if (msg.is_finish)
				break;
			msg.val /= 10.0;
			if (msg.val == 0.0)
				msg.is_finish = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(_millisecondsToWait));
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception in enterMessages: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
	}