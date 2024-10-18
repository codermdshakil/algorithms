#include <bits/stdc++.h>
using namespace std;

// implement DP
int dp[1005][1005];

int count_subset_sum(int n, int sum, int arr[])
{
    // Base Case
    if (n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // dp here
    // n and sum value can change that's why we use just n and sum
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        // option doita
        int op1 = count_subset_sum(n - 1, sum - arr[n - 1], arr);
        int op2 = count_subset_sum(n - 1, sum, arr);

        // memoization
        return dp[n][sum] = op1 + op2;
    }
    else
    {
        // ektai option
        return dp[n][sum] = count_subset_sum(n - 1, sum, arr);
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

    // print count of subset sum
    cout << count_subset_sum(n, sum, arr) << endl;

    return 0;
} 

// summary
// কত ভাবে input a দাওয়া sum  বানানু যায়
// 4 3 = 7
// 5 2 = 7
// 1 2 4 = 7
// 6 1 = 7
// total 4 ways we can make 7
