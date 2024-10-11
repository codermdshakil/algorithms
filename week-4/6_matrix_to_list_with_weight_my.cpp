#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mat[n][n];

    // create adjacency list
    vector<int> v[n];

    vector<int> costs;

    // input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = -1;
            }
        }
    }

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
            if (mat[i][j] > 0)
            {
                costs.push_back(mat[i][j]);
            }
        }
    }

    // take adjacency list value input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x : costs)
            {
                if (mat[i][j] == x)
                {
                    v[i].push_back(x);
                }
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