#include "Locker.h"
std::mutex Locker::mtx_msg;
std::condition_variable Locker::cond_msg;