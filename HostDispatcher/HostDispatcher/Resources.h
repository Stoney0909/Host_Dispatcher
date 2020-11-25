#pragma once
#include "Process.h"
class Resources
{
public:
	unsigned int Printers, Scanners, Modems, Driver;

	Resources(int newPrinterCount = 0, int newScannerCount = 0, int newModemCount = 0,int newDriverCount = 0);

	bool checkResources(Process proc);

	void allocateResources(Process proc);

	void freeResources(Process proc);

};

