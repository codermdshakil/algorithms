#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{
    // basecase
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (weight[n-1] <= W)
    {
        // two option
        int op1 = knapsack(n - 1, weight, value, W - weight[n-1]) + value[n-1];
        int op2 = knapsack(n - 1, weight, value, W);
        return max(op1, op2);
    }
    else
    {
        // option ekta e
        int op2 = knapsack(n - 1, weight, value, W);
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

    cout << knapsack(n, weight, value, W);

    return 0;
}