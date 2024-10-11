#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n;
    cin >> n;
    // create a matrix
    int mat[n][n];
    vector<Edge> edgeLists;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > 0 && i != j)
            {
                edgeLists.push_back({i, j, mat[i][j]});
            }
        }
    }

    for (Edge child : edgeLists)
    {
        cout << child.u << " " << child.v << " " << child.w << endl;
    }

    return 0;
}