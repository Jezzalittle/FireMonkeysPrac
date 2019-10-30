#pragma once
#include <vector>

class StreamTest
{
public:


	const size_t Read(const char* buf, const size_t bytes);
	const std::vector<char>& ReadAll(const char * buf);

	StreamTest();
	~StreamTest();
};

