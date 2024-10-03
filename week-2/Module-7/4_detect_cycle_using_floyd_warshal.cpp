#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, e;

int main()
{
    cin >> n >> e;

    // adjacency matrix
    ll adj[n][n];

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

    // take edge input
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        // adj[b][a] = c; // if underected
    }

    // floyd warshall logic
    // time complexity - O(v^3)
    // any node to any node shortest distance

    bool cycle = false;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // logic of floyd warshall
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    // cycle detect logic
                    if (adj[i][j] == adj[j][i] < 0)
                    {
                        cycle = true;
                        break;
                    }
                    // path relax
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // print

    if (cycle)
    {
        cout << "Cycle Found. No Answers" << endl;
    }
    else
    {
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
    }

    return 0;
}