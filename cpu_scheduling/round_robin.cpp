#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
  int n;
  cout << "Enter number of proesses : ";
  cin >> n;
  int isQueued[100] = {0};
  vector<int> process;
  vector<int> arrivalTime;
  vector<int> burstTime;
  vector<int> ct[n];
  vector<int> tat[n];
  vector<int> rt[n];
  vector<int> wt[n];

  int minProcess = 0;
  cout << "Enter data \n";

  for (int i = 0; i < n; i++)
  {
    // Arrival Time and Burst Time
    int a, b;
    cin >> a >> b;
    process.push_back(i);
    arrivalTime.push_back(a);
    burstTime.push_back(b);
    // arrival Time of i is less than arrival time of minProcess
    if (arrivalTime[i] < arrivalTime[minProcess])
    {
      minProcess = i;
    }
  }
  // cout << minProcess;
  // remaning time
  vector<int> remt(burstTime);
  int tq;
  cout << "Enter Time Quantum ";
  cin >> tq;

  queue<int> q;
  // enqueue minProcess
  q.push(minProcess);
  isQueued[minProcess] = 1;

  int arrt = arrivalTime[minProcess];
  int comt = arrivalTime[minProcess];

  while (!q.empty())
  {
    int i = q.front();
    q.pop();
    rt[i].push_back(comt - arrivalTime[i]);

    if (burstTime[i] > tq)
    {
      comt += tq;
      burstTime[i] -= tq;
    }
    else
    {
      comt += burstTime[i];
      burstTime[i] = 0;
      ct[i].push_back(comt);
      int t = comt - arrivalTime[i];
      tat[i].push_back(t);
      wt[i].push_back(t - remt[i]);
    }

    for (int j = 0; j < n; j++)
    {
      if (isQueued[j] == 0)
      {
        if (arrivalTime[j] <= comt)
        {
          q.push(j);
          isQueued[j] = 1;
        }
      }
    }
    if (burstTime[i] > 0)
    {
      q.push(i);
    }
    arrt += comt;
  }
  cout << endl;
  cout << "id"
       << " | ";
  cout << "at"
       << " | ";
  cout << "bt"
       << " | ";
  cout << "ct"
       << " | ";
  cout << "tat"
       << "| ";
  cout << "rt"
       << "| ";
  cout << "wt"
       << " | ";
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << i << " | ";
    cout << arrivalTime[i] << " | ";
    cout << remt[i] << " | ";

    cout << ct[i][0] << " | ";
    cout << tat[i][0] << " | ";
    cout << rt[i][0] << " | ";
    cout << wt[i][0] << " | ";

    cout << endl;
  }

  return 0;
}