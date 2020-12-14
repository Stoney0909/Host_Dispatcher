#include <iostream>
#include <list>
#include "Host.h"
#include "Process.h"
#include <thread>
#include <chrono>
using namespace std;

int main() {
	//Call in procs and add them to the list

	list<Process> proc_list;

	Host* host = new Host();

	host->fill_input_queue(proc_list);

	host->initialize_system();

	bool complete = false;
	while (!host->complete())
	{
		//host->check_input_queue();

		//if (host->current_proc)
		//{
		//	host->handle_curr_proc();
		//}

		//if ((host->realTime_queue.empty() || host->pri1_queue.empty() || host->pri2_queue.empty() || !host->pri3_queue.empty()) && (!host->current_proc))
		//{
		//	host->assign_curr_proc();
		//}

		this_thread::sleep_for(chrono::seconds(1));

		cout << "Sleep " << host->timer << endl;

		host->timer++;

	}
	return 0;
}