#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n], s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }

    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // take s1 value
    vector<int> v;

    // print output
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (dp[i][j] == 1)
            {
                // push dp value
                v.push_back(j);
            }
        }
    }

    // take s1 and s2 difference and minimum  sum
    int ans = INT_MAX;
    for(int val:v){
        int s1 = val;
        int s2 = s - s1;
        ans = min(ans, abs(s1-s2));
    }

    cout << ans << endl;

    return 0;
}
