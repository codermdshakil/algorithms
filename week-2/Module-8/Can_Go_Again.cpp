#include <bits/stdc++.h>
using namespace std;

// create a class to represent an edge
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
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    // Initialize distance array to INT_MAX
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    // Bellman-Ford algorithm
    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    { // O(V)
        for (Edge ed : edgeList)
        { // O(E)
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;

            // path relax
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {

                if (dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }
    }

    // Detect negative cycle
    bool cycle = false;
    for (Edge ed : edgeList)
    { // O(E)
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;

        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    int t;
    cin >> t;

    // If a negative cycle is detected
    if (cycle == true)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (t--)
        {
            int des;
            cin >> des;

            if (dis[des] == INT_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[des] << endl;
            }
        }
    }

    return 0;
}
