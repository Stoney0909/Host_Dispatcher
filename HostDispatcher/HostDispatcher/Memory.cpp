#include "Memory.h"

bool Memory::allocateMemory(Process* proc)
{

	if (allocated >= proc->mbytes)
	{
		allocated -= proc->mbytes;
		return true;
	}
	return false;
}

void Memory::unallocateMemory(Process* proc)
{
	allocated += proc->mbytes;
}
