/**
 * @file FCFS.cpp
 * @brief Spu Scheduling Algorithm: First Come First Serve
 * @about: First come first serve (FCFS) scheduling algorithm simply schedules the jobs according to their arrival time.
 * @version 0.1
 * @date 2022-06-18
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    // number of processes
    int n;
    cout << "Enter total number of Processes" << endl;
    cin >> n;

    // boolean array to track finished and unfinished process
    // true: finished
    bool finished[100] = {false};

    // arrival Time
    vector<int> at;
    // burst Time
    vector<int> bt;
    // completion Time
    vector<int> ct[n];
    // Turn around Time
    vector<int> tat[n];
    // Response Time
    vector<int> rt[n];
    // Waiting Time
    vector<int> wt[n];
    // process sequences
    vector<int> seq;

    // minimum arrival Time for a process
    // initialize to maximum integer value
    int minAt = INT32_MAX;

    // initialize to maximum integer value
    int minProcess = INT32_MAX;

    // Input Arrival Time and Burst Time for processes 0 to n-1;
    for (int i = 0; i < n; i++)
    {
        /**
         * @brief
         * a: arrival time for a process
         * b: burst time for a process
         *
         */
        int a, b;
        cout << "Enter Arrival Time and Burst Time for process " << i << " : ";
        cin >> a >> b;
        // push_back to the respective vectors
        at.push_back(a);
        bt.push_back(b);
        if (a < minAt)
        {
            minAt = a;
            minProcess = i;
        }
    }

    // current Time
    int currentTime = minAt;

    // Queue for arrived process
    queue<int> nextProcess;

    // Enqueue minProcess
    nextProcess.push(minProcess);

/**
 * @brief
 * Now we have to schedule each process according to FCFS scheme and calculate following parameters:
 * Completion Time ==> ct
 * Response Time ==> rt
 * Waiting Time ==> wt
 * Turn Around Time ==> tat
 *
 */

// exec label
exec:
    while (!nextProcess.empty())
    {
        // take current process
        int currentProcess = nextProcess.front();

        // dequeue front process
        nextProcess.pop();
        seq.push_back(currentProcess);
        finished[currentProcess] = true;

        // note its response time
        rt[currentProcess].push_back(currentTime);

        // Assume process is executed
        // update currentTime
        currentTime += bt[currentProcess];

        // note its completion time
        ct[currentProcess].push_back(currentTime);

        // note its turn around time
        tat[currentProcess].push_back(currentTime - at[currentProcess]);

        // note its waiting time
        wt[currentProcess].push_back(tat[currentProcess][0] - bt[currentProcess]);

        // now enqueue all the processes having their arrival Time < currentTime
        for (int i = 0; i < n; i++)
        {
            if (!finished[i] && at[i] <= currentTime)
            {
                nextProcess.push(i);
            }
        }
    }

    // check for any left over process
    for (int i = 0; i < n; i++)
    {
        if (!finished[i])
        {
            // if process is not finished
            nextProcess.push(i);

            // update currentTime
            currentTime = at[i];

            // jump to exec label
            goto exec;
        }
    }
    cout << endl;
    cout << "pid | at | bt | ct | tat| rt | wt " << endl;
    // Print Tabular data
    for (int i = 0; i < n; i++)
    {
        cout << "  " << i << " |  " << at[i] << " |  " << bt[i] << " |  " << ct[i][0] << " |  " << tat[i][0] << " |  " << rt[i][0] << " |  " << wt[i][0] << "  " << endl;
    }

    cout << endl
         << "Gantt chart: " << endl;

    cout << "| a | p | c |" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| " << at[seq[i]] << " | " << seq[i] << " | " << ct[seq[i]][0] << " |" << endl;
    }
    return 0;
}