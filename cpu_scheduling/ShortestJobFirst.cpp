#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processes ";
    cin >> n;
    vector<int> ct[n];
    vector<int> rt[n];
    vector<int> wt[n];
    vector<int> tat[n];
    vector<int> v[n];
    int ShortestJob = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter at and bt for process " << i << " : " << endl;
        cin >> a >> b;
        v[i].push_back(a);
        v[i].push_back(b);
        if (v[i][1] < v[ShortestJob][1])
        {
            ShortestJob = i;
        }
    }
    int completed[10] = {0};
    completed[ShortestJob] = 1;
    int completionTime = 0;
    int arrivalTime = v[ShortestJob][0];

    return 0;
}