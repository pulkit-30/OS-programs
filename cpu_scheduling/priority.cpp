#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n = 100;
int isQueued[100] = {0};

int min_arr_time = 0;
int process_exec = 0;
int arr_process = INT16_MAX;

int maxPriority = 0;
int max_priority_process = 0;

vector<int> process[100];
queue<int> q;

void FindProcess()
{
  // int count = 0;
  arr_process = INT16_MAX;
  maxPriority = 0;
  for (int i = 0; i < n; i++)
  {
    if (isQueued[i] == 0)
    {
      if (process[i][0] <= min_arr_time)
      {
        if (process[i][2] > maxPriority)
        {
          maxPriority = process[i][2];
          max_priority_process = i;
        }
      }
    }
  }

  isQueued[max_priority_process] = 1;
  q.push(max_priority_process);
}

int main()
{

  cout << "Enter the total number of processes : ";
  cin >> n;
  vector<int> ct[n];
  vector<int> rt[n];
  vector<int> tat[n];
  vector<int> wt[n];

  // process[i][0] ==> arrival time
  // process[i][1] ==> burst time
  // process[i][2] ==> priority

  for (int i = 0; i < n; i++)
  {
    int a, b, p;
    cin >> a >> b >> p;
    process[i].push_back(a);
    process[i].push_back(b);
    process[i].push_back(p);
    if (arr_process > a)
    {
      min_arr_time = a;
      arr_process = i;
    }
  }
  FindProcess();
  min_arr_time = process[q.front()][0];
  int compt = min_arr_time;
  int count = 0;
  while (count < n)
  {
    int curr_process = q.front();
    isQueued[curr_process] = 1;
    q.pop();
    int at = process[curr_process][0];
    int bt = process[curr_process][1];
    int p = process[curr_process][2];
    compt += bt;
    ct[curr_process].push_back(compt);
    tat[curr_process].push_back(compt - at);
    rt[curr_process].push_back(min_arr_time - at);
    wt[curr_process].push_back(tat[curr_process][0] - bt);
    min_arr_time += bt;
    FindProcess();
    count++;
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << ct[i][0] << " | " << tat[i][0] << " | " << rt[i][0] << " | " << wt[i][0] << endl;
  }
  return 0;
}