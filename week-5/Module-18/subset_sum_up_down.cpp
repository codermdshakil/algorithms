#include <bits/stdc++.h>
using namespace std;

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

    if (arr[n - 1] <= sum)
    {
        // option doita
        bool op1 = subset_sum(n - 1, sum - arr[n - 1], arr);
        bool op2 = subset_sum(n - 1, sum, arr);
        return op1 || op2;
    }
    else
    {
        // ektai option
        return subset_sum(n - 1, sum, arr);
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