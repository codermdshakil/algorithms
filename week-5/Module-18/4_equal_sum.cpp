#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // create a array
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }

    // jor hole sodu kaj korbo na hole NO bole dibo j equal sum kora jabe na
    if (s % 2 == 0)
    {
        int sum = s / 2;
        bool dp[n + 1][sum + 1];
        dp[0][0] = true;
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {

                if (arr[i - 1] <= j)
                {
                    // doita option
                    int op1 = dp[i - 1][j - arr[i - 1]];
                    int op2 = dp[i - 1][j];
                    dp[i][j] = op1 + op2;
                }
                else
                {
                    // ektai option
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][sum])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "NO, Odd Number" << endl;
    }

    return 0;
}