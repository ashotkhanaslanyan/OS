#include "SJF.h"
#include <stdio.h>

void sjf(struct Process proc[], int n) {
    int current_time = 0;
    int completed = 0;
    int shortest;
    int min_burst_time;

    while (completed < n) {
        shortest = -1;
        min_burst_time = 99999;

        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].burst_time < min_burst_time && proc[i].turnaround_time == 0) {
                min_burst_time = proc[i].burst_time;
                shortest = i;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        proc[shortest].waiting_time = current_time - proc[shortest].arrival_time;
        proc[shortest].response_time = proc[shortest].waiting_time;
        proc[shortest].turnaround_time = proc[shortest].waiting_time + proc[shortest].burst_time;
        current_time += proc[shortest].burst_time;
        completed++;
    }
}
