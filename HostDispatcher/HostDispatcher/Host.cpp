#include "Host.h"



void Host::check_input_queue()
{
	for (int i = 0; i < input_queue.size(); i++)
	{
		if (input_queue.front().priority == 0)
		{
			realTime_queue.push(input_queue.front());
			input_queue.pop();
		}
		else if (input_queue.front().priority == 1)
		{
			pri1_queue.push(input_queue.front());
			input_queue.pop();
		}
		else if (input_queue.front().priority == 2)
		{
			pri2_queue.push(input_queue.front());
			input_queue.pop();
		}
		else
		{
			pri3_queue.push(input_queue.front());
			input_queue.pop();
		}
	}
	
}
void Host::print_usage()
{
	cout << "Process ID" << curr_proc.process_id << endl;
	cout << "Process Arrival Time" << curr_proc.arrivalTime << endl;
	cout <<"Process priority"<< curr_proc.priority << endl;
	cout <<"Process processTime"<< curr_proc.processTime << endl;
	cout <<"Process remaining CPUTime"<< curr_proc.remCPUTime<< endl;
	cout <<"Process megaByte"<< curr_proc.mbytes << endl;
	cout <<"Process  " << curr_proc.driversReq << endl;
	cout << "Process Scanners " << curr_proc.scannersReq << endl;
	cout << "Process  " << curr_proc.printersReq << endl;
	cout << "Process memoryBlock" << curr_proc.modemsReq << endl;
}
bool Host::complete()
{
	if (realTime_queue.size() > 0)
	{
		return false;
	}
	else if (pri1_queue.size() > 0)
	{
		return false;
	}
	else if (pri2_queue.size() > 0)
	{
		return false;
	}
	else if (pri3_queue.size() > 0)
	{
		return false;
	}
	else if(current_proc != nullptr)
	{
		return false;
	}
	return true;
}

void Host::initialize_system()
{
}

void Host::fill_input_queue(list<Process> proc_list)
{
	for (int i = 0; i < proc_list.size(); i++)
	{
		input_queue.push(proc_list.front());
		proc_list.pop_front();
	}
}
