#pragma once
#include <iostream>
#include <queue>
#include <list>
#include "Process.h"
#include "Resources.h"
using namespace std;
class Host
{
private:
	//Memory Constraints
	int reserved_memory = 64;
	int total_memory = 1024;
	//Resources Constraints
	int total_printers = 2;
	int total_scanners = 1;
	int total_modems = 1;
	int total_drives = 2;

	queue<Process*> input_queue;

	Process* curr_proc;
	Resources rsrcs;

	
public:
	queue<Process> realTime_queue;
	queue<Process> pri1_queue;
	queue<Process> pri2_queue;
	queue<Process> pri3_queue;
	int timer;
	Process* current_proc;
	void print_usage();
	void check_input_queue();
	bool complete();
	void initialize_system();
	void fill_input_queue(list<Process*> proc_list);
	void handle_curr_proc();
	void assign_curr_proc();


};

