#include "Consumer.h"
#include <iostream>

Consumer::Consumer(std::list<Message>& messages)
	: _messages(messages) {};

void Consumer::operator()()
{
	int not_finish = NUM_PRODUCERS;
	Message msg;
	try
	{
		while (not_finish != 0)
		{
			{
				std::unique_lock lck(_locker.mtx_msg);
				_locker.cond_msg.wait(lck, [&]() { return !_messages.empty(); });
				msg = _messages.front();
				_messages.pop_front();	
			}
			if (msg.is_finish)
			{
				std::cout << "<" << msg.size_tid << "> finished" << std::endl;
				--not_finish;
			}
			else
			{
				std::cout << "<" << msg.size_tid << "> sent: <" << msg.val << ">" << std::endl;
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception in the Consumer: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown exception in the Consumer" << std::endl;
	}
}
