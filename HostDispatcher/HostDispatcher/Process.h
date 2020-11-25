#pragma once
#include "Memory.h"
class Process
{
public:
	int process_id, arrivalTime, priority, processTime, mbytes, remCPUTime, printersReq, scannersReq, modemsReq, driversReq;
	Memory memoryBlock;

	Process();
	Process(int process_id, int arrivalTime, int priority, int processTime, int mbytes, int remCPUTime, int printersReq, int scannersReq, int modemsReq, int driversReq);


};

