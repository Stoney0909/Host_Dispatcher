#include "Host.h"



void Host::print_usage()
{
	cout << "Process ID" << current_proc->process_id << endl;
	cout << "Process Arrival Time" << current_proc->arrivalTime << endl;
	cout << "Process priority" << current_proc->priority << endl;
	cout << "Process processTime" << current_proc->processTime << endl;
	cout << "Process remaining CPUTime" << current_proc->remCPUTime << endl;
	cout << "Process megaByte" << current_proc->mbytes << endl;
	cout << "Process  " << current_proc->driversReq << endl;
	cout << "Process Scanners " << current_proc->scannersReq << endl;
	cout << "Process  " << current_proc->printersReq << endl;
	cout << "Process memoryBlock" << current_proc->modemsReq << endl;
}

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
	totalMemory.mem = total_memory;
	rsrcs.Driver = total_drives;
	rsrcs.Modems = total_modems;
	rsrcs.Printers = total_printers;
	rsrcs.Scanners = total_scanners;
}

void Host::fill_input_queue(list<Process> proc_list)
{
	for (int i = 0; i < proc_list.size(); i++)
	{
		input_queue.push(proc_list.front());
		proc_list.pop_front();
	}
}

void Host::handle_curr_proc()
{

	if (current_proc->remCPUTime == 0)
	{
		rsrcs.freeResources(current_proc);
		totalMemory.unallocateMemory(current_proc->mbytes);
		current_proc = new Process();

	}
	else
	{
		current_proc->remCPUTime;
		check_input_queue();
		if (current_proc->priority > 0 && realTime_queue.size() > 0)
		{
			if (current_proc->priority < 3)
			{
				rsrcs.freeResources(current_proc);
				totalMemory.unallocateMemory(current_proc-> mbytes);
				current_proc->priority--;
				input_queue.push(*current_proc);
				assign_curr_proc();
			}
		}
		else if (current_proc->priority > 1 && pri1_queue.size() > 0)
		{
			if (current_proc->priority < 3)
			{
				rsrcs.freeResources(current_proc);
				totalMemory.unallocateMemory(current_proc->mbytes);
				current_proc->priority--;
				input_queue.push(*current_proc);
				assign_curr_proc();
			}
		}
		else if (current_proc->priority > 2 && pri2_queue.size() > 0)
		{
			if (current_proc->priority < 3)
			{
				rsrcs.freeResources(current_proc);
				totalMemory.unallocateMemory(current_proc->mbytes);
				current_proc->priority--;
				input_queue.push(*current_proc);
				assign_curr_proc();
			}
		}
		else
		{
			current_proc->remCPUTime--;
		}


	}
}

void Host::assign_curr_proc()
{
	if (!realTime_queue.empty())
	{
		current_proc = new Process(realTime_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		realTime_queue.pop();
	}
	else if (!pri1_queue.empty())
	{
		current_proc = new Process(pri1_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		pri1_queue.pop();
	}
	else if (!pri2_queue.empty())
	{
		current_proc = new Process(pri1_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		pri1_queue.pop();
	}
	else if(!pri3_queue.empty())
	{
		current_proc = new Process(pri3_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		pri3_queue.pop();
	}

}
