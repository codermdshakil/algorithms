#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // create a array to store values
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // take sum input
    int sum;
    cin >> sum;

    // create a dp array using n and sum
    int dp[n + 1][sum + 1];

    // initial  0 row and 0 col value true
    dp[0][0] = 1;
    // inisially 0 row and col 0 value false
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    // DP down -> up approch using loop
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

    // kon value koto bar bananu jabe
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}