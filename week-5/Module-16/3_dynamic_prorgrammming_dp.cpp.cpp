#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;

// step -> 1
ll dp[N];

ll fibonacci(ll n)
{
    // basecase
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    ll ans = fibonacci(n - 1) + fibonacci(n - 2);
    // step - 3
    dp[n] = ans;
    return ans;
}

int main()
{   

    ll n;
    cin >> n;

    // step - 2
    memset(dp, -1, sizeof(dp));
    cout << fibonacci(n) << endl;

    return 0;
}
//  dp - recursion + memoization
// Steps
// 1. create a dp array
// 2. initialaize dp all values with -1
// 3. dp[n] != -1 return dp[n] = n
// 4. dp[n] = ans;
