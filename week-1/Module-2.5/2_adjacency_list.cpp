#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // create adjacency list
    vector<int> v[n];

    // take adjacency list value
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (auto x : v[0])
    {
        cout << x << " ";
    }

    return 0;
}