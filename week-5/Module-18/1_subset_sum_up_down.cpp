#include <bits/stdc++.h>
using namespace std;

// implement DP
int dp[1005][1005];

bool subset_sum(int n, int sum, int arr[])
{
    // Base Case
    if (n == 0)
    {
        if (sum == 0)
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
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        // option doita
        bool op1 = subset_sum(n - 1, sum - arr[n - 1], arr);
        bool op2 = subset_sum(n - 1, sum, arr);
        
        // memoization
        return  dp[n][sum] = op1 || op2;
    }
    else
    {
        // ektai option
        return  dp[n][sum] = subset_sum(n - 1, sum, arr);
    }
}

int main()
{

    int n;
    cin >> n;
    // create a array to store array
    int arr[n];

    // take array input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // take sum input
    int sum;
    cin >> sum;

    // inisial dp value is -1
    memset(dp, -1, sizeof(dp));

    if (subset_sum(n, sum, arr))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}