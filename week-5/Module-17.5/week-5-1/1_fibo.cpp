#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int fibo(int n)
{
    // basecase
    if (n < 2)
    {
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}

int main()
{

    // initialize dp with -1
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}