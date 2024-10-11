#include "FCFS.h"
#include <stdio.h>

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByArrival(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrival_time > proc[j + 1].arrival_time) {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }
}

void fcfs(struct Process proc[], int n) {
    int current_time = 0;
    sortByArrival(proc, n);

    for (int i = 0; i < n; i++) {
        if (current_time < proc[i].arrival_time) {
            current_time = proc[i].arrival_time;
        }
        
        proc[i].waiting_time = current_time - proc[i].arrival_time;
        proc[i].response_time = proc[i].waiting_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        current_time += proc[i].burst_time;
    }
}
