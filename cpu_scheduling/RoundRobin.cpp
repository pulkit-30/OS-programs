/**
 * @file RoundRobin.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{

    // Total Number of Processes
    int n;
    cout << "Enter number of processes : ";
    cin >> n;

    // Maintain data for each process that is ready to exec
    // 0: not queued
    // 1: queued
    int isQueued[100] = {0};

    // input processes
    vector<int> process;
    // arrival Time
    vector<int> arrivalTime;
    // burst Time
    vector<int> burstTime;
    // completion Time
    vector<int> ct[n];
    // Turn around time
    vector<int> tat[n];
    // response Time
    vector<int> rt[n];
    // waiting Time
    vector<int> wt[n];
    // process sequence
    vector<int> seq;

    // minimum process to arrive earlier for a process
    // initialize to maximum integer value
    int minProcess = 0;

    for (int i = 0; i < n; i++)
    {

        // Arrival Time and Burst Time
        int a, b;
        cout << "Enter Arrival Time and Burst Time for process " << i << " : ";
        cin >> a >> b;
        process.push_back(i);
        arrivalTime.push_back(a);
        burstTime.push_back(b);

        // arrival Time of i is less than arrival time of minProcess
        if (arrivalTime[i] < arrivalTime[minProcess])
        {
            // update minimum arrival Time process
            minProcess = i;
        }
    }

    // remaining time
    // default initialize with burst Time
    vector<int> remt(burstTime);

    // time quantum
    int tq;
    cout << "Enter Time Quantum ";
    cin >> tq;

    // Process Sequence Queue
    queue<int> q;

    // enqueue minProcess
    q.push(minProcess);
    isQueued[minProcess] = 1;

    int currentTime = arrivalTime[minProcess];
exec:
    while (!q.empty())
    {
        int i = q.front();
        seq.push_back(i);
        // dequeue front process from sequence queue
        q.pop();

        rt[i].push_back(currentTime);

        if (remt[i] > tq)
        {
            currentTime += tq;
            remt[i] -= tq;
        }
        else
        {
            currentTime += remt[i];
            remt[i] = 0;
            ct[i].push_back(currentTime);
            tat[i].push_back(currentTime - arrivalTime[i]);
            wt[i].push_back(tat[i][0] - burstTime[i]);
        }

        // update queue
        for (int j = 0; j < n; j++)
        {
            if (isQueued[j] == 0 && arrivalTime[j] <= currentTime)
            {
                q.push(j);
                isQueued[j] = 1;
            }
        }
        // again enqueue the process if remaining > 0
        if (remt[i] > 0)
        {
            q.push(i);
        }
    }

    // check for any left over process
    for (int i = 0; i < n; i++)
    {
        if (!isQueued[i])
        {
            // if process is not finished
            q.push(i);

            // update currentTime
            currentTime += arrivalTime[i];

            // jump to exec label
            goto exec;
        }
    }

    cout << endl;
    cout << "id| at| bt| ct|tat| rt| wt| " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " | "
             << arrivalTime[i] << " | "
             << burstTime[i] << " | "
             << ct[i][0] << " | "
             << tat[i][0] << " | "
             << rt[i][0] << " | "
             << wt[i][0] << " | "
             << endl;
    }

    // cout << endl
    //      << "Gantt chart: " << endl;

    // cout << "| a | p | c |" << endl;
    // for (int i = 0; i < seq.size(); i++)
    // {
    //     cout << "| " << arrivalTime[seq[i]] << " | " << seq[i] << " | " << rt[seq[i]][0] << " |" << endl;
    // }
    return 0;
}