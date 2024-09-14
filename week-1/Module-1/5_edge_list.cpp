#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    // make a pair list so that I can stored edge
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    // for (pair<int, int> x : v)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}