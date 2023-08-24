#pragma once
#include <mutex>

typedef struct Locker {
	static std::mutex mtx_msg;
	static std::condition_variable cond_msg;
}Locker;