#include <bits/stdc++.h>
using namespace std;

const int N = 100;

// adjacency list with store 2 value 1. konta connected 2. cost
vector<pair<int, int>> v[N];

// distance array to store distance
int dis[N];

// compare class asseding order based on second values
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        // sort asseding order based on secon value
        return a.second > b.second;
    }
};

// Dijkstra Obtimaized version
// time complexity - O(V+E) * log v  or  (ElogV);
void dijkstra_obtimaized(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.first;
        int parentCost = parent.second;

        // get childrens from parent
        for (pair<int, int> child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]}); // push children to queue
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
 

    dijkstra_obtimaized(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

// Time complexity of dijkstra optimaized version - O(V+E) * log v  or  (ElogV);
