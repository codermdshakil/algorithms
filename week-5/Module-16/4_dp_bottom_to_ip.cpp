#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    a[0] = 0;
    a[1] = 1;
    
    // time complexity - O(N)
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    // for (int i = 0; i <=  n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    cout << a[n] << endl;

    return 0;
}