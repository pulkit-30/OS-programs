#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> Edges[100];
  vector<int> Adj_resource[100];
  vector<int> Adj_process[100];

  bool run = 1;
  int i = 0;
  while (run)
  {
    int process;
    int resource;
    cout << "Enter Edge";
    cin >> resource >> process;
    Edges[i].push_back(resource);
    Edges[i].push_back(process);
    ++i;
    cout << "Wanna add more edges[1/0]";
    cin >> run;
  }
  int total_resources = i;

  cout << "Is there any edge b/w process and resource";
  cin >> run;
  while (run)
  {
    int process;
    int resource;
    cout << "Enter Edge";
    cin >> process >> resource;
    Edges[i].push_back(process);
    Edges[i].push_back(resource);
    ++i;
    cout << "Wanna add more edges[1/0]";
    cin >> run;
  }
  int total_processes = i - total_resources;
  i = 0;
  for (int j = 0; j < total_resources; j++)
  {
    i++;
    Adj_resource[Edges[j][0]].push_back(Edges[j][1]);
  }
  for (int j = total_resources; j < total_processes; j++)
  {
    i++;
    Adj_process[Edges[j][0]].push_back(Edges[j][1]);
  }

  for (int j = 0; j < total_resources; j++)
  {
    cout << "R" << j << " : ";
    for (int k = 0; k < Adj_resource[j].size(); k++)
    {
      cout << "P" << Adj_process[j][k] << " , ";
    }
    cout << endl;
  }
  for (int j = 0; j < total_processes; j++)
  {
    cout << "P" << j << " : ";
    for (int k = 0; k < Adj_process[j].size(); k++)
    {
      cout << "R" << Adj_process[j][k] << " , ";
    }
    cout << endl;
  }
}