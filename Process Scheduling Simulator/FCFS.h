#ifndef FCFS_H
#define FCFS_H

#include "Process.h"

void swap(struct Process *a, struct Process *b);
void sortByArrival(struct Process proc[], int n);
void fcfs(struct Process proc[], int n);
void printProcesses(struct Process proc[], int n);

#endif
