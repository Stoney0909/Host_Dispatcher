#pragma once
class Memory
{
public:
	unsigned int offset, size;
	int allocated;
	Memory* prev;
	Memory* next;
	


};

