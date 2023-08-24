#pragma once
#include <mutex>

/// <summary>
///The Locker struct provides mutex and condition_variable instances for synchronization.
///It's intended to be used as a namespace-like structure to hold these synchronization primitives.
/// </summary>
typedef struct Locker {
	static std::mutex mtx_msg;
	static std::condition_variable cond_msg;
}Locker;