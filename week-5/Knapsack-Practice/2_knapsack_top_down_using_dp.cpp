#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
const int maxW = 1000;

int dp[maxN][maxW];

int knapsack(int n, int weight[], int value[], int W)
{
    // basecase
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // Dp  Memoization
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (weight[n - 1] <= W)
    {
        // two option
        int op1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int op2 = knapsack(n - 1, weight, value, W);
        dp[n][W] = max(op1, op2);
        return dp[n][W];
    }
    else
    {
        // option ekta e
        int op2 = knapsack(n - 1, weight, value, W);
        dp[n][W] = op2;
        return dp[n][W];
    }
}

int main()
{

    int n;
    cin >> n;
    int weight[n], value[n];
    // take weight input
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    // take value input
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    // inisially dp all index value -1
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, weight, value, W);

    return 0;
}