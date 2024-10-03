#include <bits/stdc++.h>
using namespace std;

int n, e;

int main()
{
    cin >> n >> e;

    // adjacency matrix
    int adj[n][n];

    // adjacency matrix default all value infinite or INT_MAX
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    // inisially all distace value is INT_MAX

    // take edge input
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        // adj[b][a] = c; // if underected
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // logic of floyd warshall
                if (adj[i][k] < INT_MAX && adj[i][k] < INT_MAX && adj[k][j] < INT_MAX && adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}