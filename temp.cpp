#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // number of test cases
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, answer = 0, flag = 0;
        cin >> n;
        string s;
        cin >> s;
        int len = s.length();
        int CP = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'P')
                CP++;
        }
        float percent_att = ((CP * 100) / n);
        if (percent_att < 75)
        {

            for (int i = 2; i < len - 2; i++)
            {
                if (s[i] == 'A')
                {
                    if ((s[i - 1] == 'P' || s[i - 2] == 'P') && (s[i + 1] == 'P' || s[i + 2] == 'P'))
                    {
                        answer++;
                        CP++;
                        percent_att = ((CP * 100) / n);
                        if (percent_att >= 75.0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            flag = 1;
        }
        if (flag == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << answer << endl;
        }
        t--;
    }
    return 0;
}