#include <bits/stdc++.h>
using namespace std;

// implement DP
int dp[1005][1005];

bool subset_sum(int n, int target, int arr[])
{
    // Base Case
    if (n == 0)
    {
        if (target == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // dp here
    // n and sum value can change that's why we use just n and sum
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    if (arr[n - 1] <= target)
    {
        // option doita
        int op1 = subset_sum(n - 1, target - arr[n - 1], arr);
        int op2 = subset_sum(n - 1, target, arr);

        // memoization
        return dp[n][target] = op1 + op2;
    }
    else
    {
        // ektai option
        return dp[n][target] = subset_sum(n - 1, target, arr);
    }
}

int main()
{

    int test;
    cin >> test;
    while (test--)
    {
        int total_sum = 1000;
        int n, sum;
        cin >> n >> sum;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int target = total_sum - sum;

        // inisial dp value is -1
        memset(dp, -1, sizeof(dp));

        if (total_sum == sum)
        {
            cout << "YES\n";
        }
        else
        {

            if (subset_sum(n, target, arr))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}