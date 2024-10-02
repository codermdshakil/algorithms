#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;

int nodes, edges;

// cost/weight , value store
vector<pair<int, int>> adj[100005];

// distance array
long long int dis[100005];

// track children parent
long long int parent[100005];

bool vis[100005];

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

        // parent node visited
        vis[parentNode] = true;

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
        dis[i] = INF;
    }

    dijkstra(src);

    // for (int i = 1; i <= nodes; i++)
    // {
    //     cout << dis[i] << " ";
    // }


    if(vis[nodes] != true){
        cout << -1 << endl;
        return 0;
    }

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

// this problem solution:: https://codeforces.com/problemset/problem/20/c
// I learn
// ------------
// 1. dijkstra algorithm without using cmp class
// 2. path printing 
// 3. if there is no path then print -1
