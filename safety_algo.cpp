#include <iostream>
#include <vector>
using namespace std;
bool RunSafetyAlgo(vector<int> max[], vector<int> allocation[], vector<int> available, vector<int> need[], int n, int r)
{
  // Array to store the finished processes
  bool isFinished[n] = {false};
  int FinishProcesses = 0;
  // Work vector
  vector<int> Work = available;

  for (int i = 0; i < n; i++)
  {
    if (!isFinished[i])
    {
      int isSafe = false;
      for (int j = 0; j < n; j++)
      {
        if (Work[j] >= need[i][j])
        {
          isSafe = true;
        }
        else
        {
          // break the inner loop and jump to outer loop
          break;
        }
      }
      // when need of Process is small then Work
      if (isSafe)
      {
        for (int j = 0; j < n; j++)
        {
          Work[j] -= need[i][j];
        }
        isFinished[i] = true;
      }
      else
      {
        // continue iterating the loop from index 0;
        i = -1;
        // i++
      }
    }
    else
    {
      FinishProcesses++;
    }
  }
  return false;
}

int main()
{
  // Total number of processes
  int n;
  cout << "Enter the number of processes" << endl;
  cin >> n;

  // Resources
  int r;
  cout << "Enter the total resources : ";
  cin >> r;

  // Vectors
  vector<int> process[n];
  vector<int> max[n];
  vector<int> allocation[n];
  vector<int> available;
  vector<int> need[n];

  // Loop to get process data
  for (int i = 0; i < n; i++)
  {

    cout << "Enter Max of process " << i << " : ";
    for (int j = 0; j < r; j++)
    {
      int temp;
      cin >> temp;
      max[i].push_back(temp);
    }
    cout << "Enter Allocation of process " << i << " : ";
    for (int j = 0; j < r; j++)
    {
      int temp;
      cin >> temp;
      allocation[i].push_back(temp);
    }
  }

  // Available Processes
  cout << "Enter Available of resources";
  for (int j = 0; j < r; j++)
  {
    int temp;
    cin >> temp;
    available.push_back(temp);
  }

  // Need of Processes
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < r; j++)
    {
      int temp = max[i][j] - allocation[i][j];
      need[i][j] = temp;
    }
  }

  RunSafetyAlgo(max, allocation, available, need, n, r);

  return 0;
}