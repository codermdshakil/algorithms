#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // create adjacency list
    vector<int> arr[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    // 0 er sathe kon kon node connected ta ber koro
    // for (auto x : arr[0])
    // {
    //     cout << x << " "; // 4 2 3 5 1
    // }

    for (int i = 0; i < n; i++)
    {
        cout << "Index - " << i << " values = ";
        for (auto x : arr[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}