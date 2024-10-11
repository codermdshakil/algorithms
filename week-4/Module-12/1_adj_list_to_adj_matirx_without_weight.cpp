#include <bits/stdc++.h>
using namespace std;

void convert_adjList_to_adjMatrix(int n, vector<int> adj[])
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
                adj_matrix[i][j] = 1;
            }
            else
            {
                adj_matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // get childrens
        for (int child : adj[i])
        {
            adj_matrix[i][child] = 1;
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
    vector<int> v[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    convert_adjList_to_adjMatrix(n, v);

    return 0;
}