#include "StreamTest.h"
#include <ctype.h>


const size_t StreamTest::Read(const char * buf, const size_t bytes)
{
	size_t counter = 0;
	
	//while buf doesn't equal a null terminator
	while (*buf != '\0')
	{
		//if the counter is greater or equal to the input size
		if (counter >= bytes)
			break;
		//else keep iterating and counting
		++counter;
		++buf;
	}

	//return the count
	return counter;
}

const std::vector<char>& StreamTest::ReadAll(const char * buf)
{
	//get the length of the input
	size_t len = Read(buf, std::numeric_limits<size_t>::max());
	std::vector<char>* returnValues = new std::vector<char>();

	//iterate over length and add each byte to the vector
	for (size_t i = 0; i < len; i++)
	{
		returnValues->push_back(buf[i]);
	}


	return *returnValues;
}

StreamTest::StreamTest()
{
}


StreamTest::~StreamTest()
{
}
