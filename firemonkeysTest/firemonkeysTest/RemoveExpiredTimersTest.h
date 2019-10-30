#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <vector>

class Timer
{
public:
	bool expired;
	char* text;
	Timer();
	~Timer();
};


class RemoveExpiredTimersTest
{
public:
	void beginTest(std::vector<Timer*>& a_timers);
};

