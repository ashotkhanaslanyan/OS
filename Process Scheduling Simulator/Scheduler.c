#include <stdio.h>
#include "FCFS.h"
#include "SJF.h"

void displayGanttChart(struct Process proc[], int n) {
    printf("\nGantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", proc[i].pid);
    }
    printf("|\n");
}


void printProcesses(struct Process proc[], int n) {
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, 
                proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }
}

void displayAverages(struct Process proc[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
        total_response_time += proc[i].response_time;
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    double avg_response_time = (double)total_response_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

int main() {
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n], proc_copy[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].pid = i + 1;
    }

    for (int i = 0; i < n; i++) {
        proc_copy[i] = proc[i];
    }

    fcfs(proc, n);
    printf("\n=== First Come First Served (FCFS) ===\n");
    displayGanttChart(proc, n);
    printProcesses(proc, n);
    displayAverages(proc, n);
    sjf(proc_copy, n);
    printf("\n=== Shortest Job First (SJF) ===\n");
    displayGanttChart(proc_copy, n);
    printProcesses(proc_copy, n);
    displayAverages(proc_copy, n);
    
    return 0;
}
