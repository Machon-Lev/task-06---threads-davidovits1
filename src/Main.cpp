#include"Producer.h"
#include"Consumer.h"
#include <thread>

int main()
{

	std::list<Message> messages;
	Consumer c1(messages);
	Producer p1(messages, 30);
	Producer p2(messages, 40);

	std::thread tConsumer(c1);
	std::thread tProducer1(p1);
	std::thread tProducer2(p2);

	tProducer1.join();
	tProducer2.join();
	tConsumer.join();

	return 0;
}