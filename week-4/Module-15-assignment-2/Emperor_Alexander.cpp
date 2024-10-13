#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;

ll parent[N];
ll group_size[N];

// Initialize function
void dsu_initialize(ll sz)
{
    for (ll i = 0; i < sz; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

// Find leader
ll dsu_find(ll node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    else
    {
        ll leader = dsu_find(parent[node]);
        // Path compression
        parent[node] = leader;
        return leader;
    }
}

// DSU union by size
void dsu_union_by_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);

    if (leaderA != leaderB)
    {
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

// Compare function
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    ll n, e;
    cin >> n >> e;

    dsu_initialize(n);

    // Create edge list
    vector<Edge> edgeList;
    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    // Sort edges based on weight
    sort(edgeList.begin(), edgeList.end(), cmp);

    ll totalCost = 0;
    ll roadsUsed = 0;
    ll redundantRoads = 0;

    for (auto ed : edgeList)
    {
        ll u = ed.u;
        ll v = ed.v;
        ll w = ed.w;

        ll leaderU = dsu_find(u);
        ll leaderV = dsu_find(v);

        // If they are already connected, it's a redundant road
        if (leaderU == leaderV)
        {
            redundantRoads++;
        }
        else
        {
            dsu_union_by_size(u, v);
            totalCost += w;
            roadsUsed++;
        }
    }

    // Check if all cities are connected
    if (roadsUsed < n - 1)
    {
        cout << "Not Possible" << '\n';
    }
    else
    {
        cout << redundantRoads << " " << totalCost << '\n';
    }

    return 0;
}
