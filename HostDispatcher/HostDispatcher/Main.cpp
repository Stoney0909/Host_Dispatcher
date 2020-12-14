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

	
	string line, str;
	ifstream myfile;
	
	myfile.open("File.txt"); // create a list of processes in your computer directory 
	   
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
		proc_list.push_back(*p); //Pushing them into the list
		while (!nums.empty())
		{
			nums.pop_back();
		}
	}

	host->initialize_system();
	host->fill_input_queue(proc_list);

	bool complete = false;
	while (!host->complete())
	{
		host->check_input_queue();

		if (host->current_proc)
		{
			host->handle_curr_proc();
		}

		if ((host->realTime_queue.empty() || host->pri1_queue.empty() || host->pri2_queue.empty() || !host->pri3_queue.empty()) && (!host->current_proc))
		{
			host->assign_curr_proc();
		}

		this_thread::sleep_for(chrono::seconds(1));

		cout << "Sleep " << host->timer << endl;

		host->timer++;

	}
	return 0;
}