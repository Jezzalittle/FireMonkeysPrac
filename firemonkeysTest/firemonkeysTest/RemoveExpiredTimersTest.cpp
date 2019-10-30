#include "RemoveExpiredTimersTest.h"


Timer::Timer()
{
	//pick a random number between 0 and 19
	size_t size = rand() % 20 + 5;

	//make the size of the text char array to that random value
	text = new char[size];

	//iterate over size and give the text a random char from the alphabet 
	for (size_t i = 0; i < size; i++)
	{
		text[i] = 'a' + ((char)rand() % 26);
	}
	
	//add a null terminator to the end of the char array
	text[size] = '\0';

	//set done to a random bool
	expired = rand() % 2 == 0 ? false : true;

	//print the results we got
	std::cout << text << " is " << (expired == false ? "Running" : "Expired") << std::endl;

}

Timer::~Timer()
{
	//clean up time
	delete[] text;
	delete text;
}

void RemoveExpiredTimersTest::beginTest(std::vector<Timer*>& a_timers)
{
	//start a loop from the beginning of the timers array and don't stop until it = the end of the array
	for (std::vector<Timer*>::iterator it = a_timers.begin(); it != a_timers.end();)
	{
		//print the values of the Text array 
		std::cout << (*it)->text << std::endl;

		//continue iterating 
		it++;
	}

	std::cout << std::endl;

	//start a loop from the beginning of the timers array and don't stop until it = the end of the array
	for (std::vector<Timer*>::iterator it = a_timers.begin(); it != a_timers.end();)
	{
		//if the current timer is expired
		if ((*it)->expired == true)
		{
			std::cout << "Removing " << (*it)->text << " because it has expired" << std::endl;
			//set it to the next index in the array and remove the old one
			it = a_timers.erase(it);
		}
		//else just Increase it by one
		else
		{
			it++;
		}
	}

	std::cout << std::endl;

	//print the results 

	//start a loop from the beginning of the timers array and don't stop until it = the end of the array
	for (std::vector<Timer*>::iterator it = a_timers.begin(); it != a_timers.end();)
	{
		std::cout << (*it)->text << std::endl;
		it++;
	}

	std::cout << std::endl;

}
