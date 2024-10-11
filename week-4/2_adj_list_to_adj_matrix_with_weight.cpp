#include <bits/stdc++.h>
using namespace std;

void convert_adjList_to_adjMatrix(int n, vector<pair<int, int>> adj[])
{
    // 1. create adjacency matrix using size n
    int adj_matrix[n][n];

    // inisial all value 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_matrix[i][j] = 0;
            }
            else
            {
                adj_matrix[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // get childrens
        for (pair<int, int> child : adj[i])
        {
            int childNode = child.first;
            int cost = child.second;
            adj_matrix[i][childNode] = cost;
        }
    }

    // print matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    convert_adjList_to_adjMatrix(n, v);

    return 0;
}