#include "Host.h"



void Host::print_usage() //Prints the current process 
{
	cout << "Process ID:" << current_proc->process_id << endl;
	cout << "Process Arrival Time:" << current_proc->arrivalTime << endl;
	cout << "Process priority:" << current_proc->priority << endl;
	cout << "Process processTime:" << current_proc->processTime << endl;
	cout << "Process remaining CPUTime:" << current_proc->remCPUTime << endl;
	cout << "Process megaByte:" << current_proc->mbytes << endl;
	cout << "Drivers:" << current_proc->driversReq << endl;
	cout << "Scanners:" << current_proc->scannersReq << endl;
	cout << "Printers:" << current_proc->printersReq << endl;
	cout << "Modems:" << current_proc->modemsReq << endl;
}

void Host::check_input_queue()//Sorts out input into the proper queue
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

bool Host::complete()//Checks if the program has completed all tasks
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
	else if(input_queue.size() > 0)
	{
		return false;
	}
	return true;
}

void Host::initialize_system()//Creates the system variables
{
	totalMemory.mem = total_memory;
	rsrcs.Driver = total_drives;
	rsrcs.Modems = total_modems;
	rsrcs.Printers = total_printers;
	rsrcs.Scanners = total_scanners;
}

void Host::fill_input_queue(list<Process> proc_list)//Takes proc list and puts it into input queue
{
	while (!proc_list.empty())
	{
		input_queue.push(proc_list.front());
		proc_list.pop_front();
	}
		
}

void Host::handle_curr_proc()
{

	if (current_proc->remCPUTime == 0)//unallocateds resources and memory and sets curr proc to null at the end of the process
	{
		rsrcs.freeResources(current_proc);
		totalMemory.unallocateMemory(current_proc->mbytes);
		current_proc = nullptr;

	}
	else
	{
		current_proc->remCPUTime;
		check_input_queue();
		if (current_proc->priority > 0 && realTime_queue.size() > 0)//Checks to see if there are higher priority procs
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

void Host::assign_curr_proc()//Checks queues for procs and sets the curr proc to the highest priority
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
	if (!pri1_queue.empty())
	{
		current_proc = new Process(pri1_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		pri1_queue.pop();
	}
	if (!pri2_queue.empty())
	{
		current_proc = new Process(pri2_queue.front());
		rsrcs.allocateResources(current_proc);
		if (!totalMemory.allocateMemory(current_proc->mbytes))
		{
			cout << "Not enough memory for allocation!" << endl;
		};
		pri2_queue.pop();
	}
	if(!pri3_queue.empty())
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
