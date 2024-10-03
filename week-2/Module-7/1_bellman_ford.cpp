#include <bits/stdc++.h>
using namespace std;

// create a edge object where we store  u, u and thier cost c
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
// create a distance array
int dis[N];

int main()
{
    // input node and edge
    int n, e;
    cin >> n >> e;

    // create a edgeList to store  u, v and c
    vector<Edge> edgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    // print edges and cost for checking
    // for (Edge ed : edgeList)
    // {
    //     cout << ed.u << " " << ed.v << " " << ed.c << endl;
    // }

    // inisial value of dis array INT_Max
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    // Bellman Ford algo
    dis[0] = 0;
    for (int i = 1; i <= n - 1; i++) // O(V)
    {
        for (Edge ed : edgeList) // O(E)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    // Time Complexity Of Bellman Ford = O(V*E);
    
    // print output
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> "<<dis[i] << endl;
    }

    return 0;
}