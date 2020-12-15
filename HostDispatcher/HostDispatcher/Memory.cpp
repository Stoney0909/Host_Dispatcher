#include "Memory.h"

Memory::Memory()
{
	mem = 0;
}

bool Memory::allocateMemory(int memory)
{

	if (mem >= memory)
	{
		mem -= memory;
		return true;
	}
	return false;
}

void Memory::unallocateMemory(int memory)
{
	mem += memory;
}
