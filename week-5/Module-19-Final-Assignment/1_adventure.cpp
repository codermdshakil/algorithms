#include <bits/stdc++.h>
using namespace std;

// knapsack implement
int knapsack(int n, int weight[], int value[], int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // loop approch
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weight[i - 1] <= w)
            {
                // two option
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            }
            else
            {
                // option ektai
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // last call with DP max value
    return dp[n][W];
}

int main()
{
    // testcase
    int t;
    // input testcase
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        int weight[n], value[n];

        // Take weight input
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        // Take value input
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }
        // called knapsack
        cout << knapsack(n, weight, value, W) << endl;
    }

    return 0;
}
