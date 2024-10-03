#include <bits/stdc++.h>
using namespace std;

const int N = 100;

// adjacency list with store 2 value 1. konta connected 2. cost
vector<pair<int, int>> v[N];

// distance array to store distance
int dis[N];

// dijkstra naive 
// Time complexity of Dijkstra Naive version - O(V*E)
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        int parentNode = parent.first;
        int parentCost = parent.second;

        // get childrent from parent 
        for (pair<int, int> child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = parentCost + childCost;
                q.push({childNode, dis[childNode]}); // push children to queue with distance
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    // inisially distance array value infinite

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}


