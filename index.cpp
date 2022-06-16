#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int t, d;
        int sum2 = 0;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> d;
            if (t - k > 0 || ans)
            {
                t = t - k;
                sum2 = sum2 + t * d;
                ans = true;
                k = 0;
            }
            else
            {
                k = k - t;
            }
        }
        cout << sum2 << endl;
    }
    return 0;
}