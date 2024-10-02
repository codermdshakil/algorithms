#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

// cost/weight , value store
vector<pair<int, int>> adj[100005];

// distance array
int dis[100005];

// track children parent
int parent[100005];

void dijkstra(int src)
{

    // default priority queue is follow maxHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});
    dis[src] = 0;
    parent[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int parentCost = par.first;
        int parentNode = par.second;

        for (pair<int, int> child : adj[parentNode])
        {

            // get child node cost and value
            int childCost = child.first;
            int childNode = child.second;

            // path relax
            if (dis[parentNode] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
                pq.push({dis[childNode], childNode});

                // childNode parent is parentNode
                parent[childNode] = parentNode;
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int src = 1;

    // inisially distance array all value max
    for (int i = 1; i <= nodes; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(src);

    // for (int i = 1; i <= nodes; i++)
    // {
    //     cout << dis[i] << " ";
    // }

    // path printing

    int current = nodes;

    // to store path
    vector<int> path;

    while (true)
    {
        path.push_back(current);

        if (current == src)
        {
            break;
        }
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    for (auto x : path)
    {
        cout << x << " ";
    }

    return 0;
}