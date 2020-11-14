#include "Process.h"

Process::Process()
{
	process_id = 0;
	arrivalTime = 0;
	priority = 0;
	processTime = 0;
	mbytes = 0;
	remCPUTime = 0;
	printersReq = 0;
	scannersReq = 0;
	modemsReq = 0;
	driversReq = 0;

}

Process::Process(int process_id, int arrivalTime, int priority, int processTime, int mbytes, int remCPUTime, int printersReq, int scannersReq, int modemsReq, int driversReq)
{
	this->process_id = process_id;
	this->arrivalTime = arrivalTime;
	this->priority = priority;
	this->processTime = processTime;
	this->mbytes = mbytes;
	this->remCPUTime = remCPUTime;
	this->printersReq = printersReq;
	this->scannersReq = scannersReq;
	this->modemsReq = modemsReq;
	this->driversReq = driversReq;
}

