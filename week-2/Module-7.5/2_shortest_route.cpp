#include <bits/stdc++.h>
#define ll long long int
// max 10^9
const long long int INF = 1e18 + 5;
using namespace std;

int main()
{
    ll n, e, q;
    cin >> n >> e >> q;

    // adjacency matrix
    ll adj[n + 5][n + 5];

    // adjacency matrix default all value infinite or INT_MAX
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
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
        adj[b][a] = c; // if underected
    }

    // floyd warshall logic
    // time complexity - O(v^3)
    // any node to any node shortest distance

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // logic of floyd warshall
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    // path relax
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // output   
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj[s][d] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[s][d] << endl;
        }
    }

    return 0;
}