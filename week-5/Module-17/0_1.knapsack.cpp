#include <bits/stdc++.h>
using namespace std;

// knapsack implementaion
int knapsack(int n, int weight[], int value[], int W)
{
    // base case
    if (n == 0 || W == 0)
        return 0;

    if (weight[n-1] <= W)
    {
        // doita option
        // 1. niye dekhbo
        // 2 na niye dekhbo
        int op1 = knapsack(n - 1, weight, value, W - weight[n-1]) + value[n-1];
        int op2 = knapsack(n - 1, weight, value, W);
        return max(op1, op2);
    }

    else
    {
        // ektai option
        // na niyei e dekhte hobe
        int op2 = knapsack(n - 1, weight, value, W);
        return op2;
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

    // take weight input
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    // total of knapsack
    int W;
    cin >> W;

    // n-1 means last index ta dise
    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}