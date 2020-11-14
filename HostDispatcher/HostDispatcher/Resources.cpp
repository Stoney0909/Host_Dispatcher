#include "Resources.h"

Resources::Resources(int newPrinterCount, int newScannerCount, int newModemCount, int newDriverCount)
{
	Printers = newPrinterCount;
	Scanners = newScannerCount;
	Modems = newModemCount;
	Driver = newDriverCount;
}

bool Resources::checkResources(Process proc)
{
	if (Printers >= proc.printersReq && Scanners >= proc.scannersReq && Modems >= proc.modemsReq && Driver >= proc.driversReq)
	{
		return true;
	}
	return false;
}

void Resources::allocateResources(Process proc)
{
	Printers -= proc.printersReq;
	Scanners -= proc.scannersReq;
	Modems -= proc.modemsReq;
	Driver -= proc.driversReq;
}

void Resources::freeResources(Process proc)
{
	Printers += proc.printersReq;
	Scanners += proc.scannersReq;
	Modems += proc.modemsReq;
	Driver += proc.driversReq;
}


