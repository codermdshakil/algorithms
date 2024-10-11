#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mat[n][n];

    // create adjacency list
    vector<int> v[n];

    // input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // take adjacency list value input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                v[i].push_back(j);
            }
        }
    }

    // print adjacency list value
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int child : v[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}