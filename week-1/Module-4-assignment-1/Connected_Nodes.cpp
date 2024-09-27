#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> v[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {

        int idx;
        cin >> idx;

        // if idx value don't exits in v
        if (v[idx].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            // sort dessending order
            sort(v[idx].begin(), v[idx].end(), greater<int>());
            // print idx value from v
            for (auto x : v[idx])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}