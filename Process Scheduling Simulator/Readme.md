### Step 1: Clone the Repository or Download Files

Clone this repository or download the files into a directory:

```bash
git clone git@github.com:ashotkhanaslanyan/OS.git
```

Or manually download the required files.

### Step 2: Compile the Code

Navigate to the directory where the files are located and compile the program using the GCC compiler:

```bash
cd OS/Process\ Scheduling\ Simulator/
gcc Scheduler.c FCFS.c SJF.c -o scheduler
```

This will generate an executable file named `scheduler`.

### Step 3: Run the Program

To run the program, use the following command:

```bash
./scheduler
```

### Step 4: Input Process Details

After running the program, it will ask for the number of processes and the details (arrival time and burst time) for each process:

```
Enter number of processes: 4
Enter arrival time and burst time for process 1: 0 8
Enter arrival time and burst time for process 2: 1 4
Enter arrival time and burst time for process 3: 2 9
Enter arrival time and burst time for process 4: 3 5
```

### Example Output (FCFS):

```
=== First Come First Served (FCFS) ===
Gantt Chart: | P1 |   P2   |   P3   |   P4   |
PID     AT     BT     WT     TAT    RT
1       0      8      0      8      0
2       1      4      7      11     7
3       2      9      9      18     9
4       3      5      14     19     14

Average Waiting Time: 7.50
Average Turnaround Time: 14.00
Average Response Time: 7.50
```

### Example Output (SJF):

```
=== Shortest Job First (SJF) ===
Gantt Chart: | P2 | P4 |   P1   |   P3   |
PID     AT     BT     WT     TAT    RT
2       1      4      0      4      0
4       3      5      2      7      2
1       0      8      7      15     7
3       2      9      12     21     12

Average Waiting Time: 5.25
Average Turnaround Time: 11.75
Average Response Time: 5.25
```
