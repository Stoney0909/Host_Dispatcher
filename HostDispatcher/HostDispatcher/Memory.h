#pragma once
#include "Process.h"
class Memory
{
public:
	int mem;

	
	Memory();
	bool allocateMemory(int memory);
	void unallocateMemory(int memory);
};

