#include <iostream>
#include <list>
#include "Host.h"
#include "Process.h"
#include <thread>
#include <chrono>
#include "Process.h"
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
using namespace std;

int main() {
	//Call in procs and add them to the list

	list<Process> proc_list;
	vector <int> nums;
	Host* host = new Host();

	host->fill_input_queue(proc_list);
	string line, str;
	ifstream myfile;
	
	myfile.open("C:/Users/Owner/Documents/Process.txt"); // create a list of processes in your computer directory 
	    //12 0 1 64 0 0 0 0 9 10      has to be in this format
		//12 1 2 128 1 0 0 1 9 10
		//13 3 6 128 1 0 1 2 9 10
	if (!myfile.is_open()) {
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	while (getline(myfile, line)) {
		int process_id, arrivalTime, priority, processTime, mbytes, remCPUTime, printersReq, scannersReq, modemsReq, driversReq;
		istringstream ss(line);
		string word; 
		while (ss >> word)
		{
			nums.push_back(stoi(word));//Putting into an array
			cout << word << "\n";
		}
		for (int i = 0; i < nums.size(); i++) //Setting the argument to the number
		{
			if (i == 0)
			{
				process_id = nums[i];
			}
			if (i == 1)
			{
				arrivalTime = nums[i];
			}
			if (i == 2)
			{
				priority = nums[i];
			}
			if (i == 3)
			{
				processTime = nums[i];
			}
			if (i == 4)
			{
				mbytes = nums[i];
			}
			if (i == 5)
			{
				remCPUTime = nums[i];
			}
			if (i == 6)
			{
				printersReq = nums[i];
			}
			if (i == 7)
			{
				scannersReq = nums[i];
			}
			if (i == 8)
			{
				modemsReq = nums[i];
			}
			if (i == 9)
			{
				driversReq = nums[i];
			}

		}
		Process* p = new Process(process_id, arrivalTime, priority, processTime, mbytes, remCPUTime, printersReq, scannersReq, modemsReq, driversReq);
		proc_list.push_back(*p);
		while (!nums.empty())
		{
			nums.pop_back();
		}
	}
	host->initialize_system();

	bool complete = false;
	while (host->timer < 20)
	{
	//	//host->check_input_queue();

	//	//if (host->current_proc)
	//	//{
	//	//	host->handle_curr_proc();
	//	//}

	//	//if ((host->realTime_queue.empty() || host->pri1_queue.empty() || host->pri2_queue.empty() || !host->pri3_queue.empty()) && (!host->current_proc))
	//	//{
	//	//	host->assign_curr_proc();
	//	//}

		this_thread::sleep_for(chrono::seconds(1));
		cout << "Sleep " << host->timer << endl;
		host->timer++;

	}
	return 0;
}