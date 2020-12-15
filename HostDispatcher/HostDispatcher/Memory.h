#pragma once
#include "Process.h"
class Memory
{
public:
	unsigned int offset, size;
	int allocated;
	Memory* prev;
	Memory* next;
	
	bool allocateMemory(Process* proc);
	void unallocateMemory(Process* proc);
};

