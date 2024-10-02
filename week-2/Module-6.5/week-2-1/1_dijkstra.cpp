#include <bits/stdc++.h>
using namespace std;

int nodes, edges;

// cost/weight , value store
vector<pair<int, int>> adj[100005];

// distance array
int dis[100005];

void dijkstra(int src)
{

    // default priority queue is follow maxHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentCost = parent.first;
        int parentNode = parent.second;

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

    for (int i = 1; i <= nodes; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}