#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int group_size[N];

// inisialze function
void dsu_initialize(int sz)
{
    for (int i = 0; i < sz; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

// find leader
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    else
    {
        int leader = dsu_find(parent[node]);
        // path compression
        parent[node] = leader;
        return leader;
    }
}

// dsu union by size
void dsu_union_by_size(int node1, int node2)
{

    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

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

// compare function
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    // create edge list
    vector<Edge> edgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    // sort
    sort(edgeList.begin(), edgeList.end(), cmp);

    int totalCost = 0;
    for (auto ed : edgeList)
    {
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;

        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);

        if(leaderU == leaderV){
            continue;
        }
        else{
            dsu_union_by_size(u, v);
            totalCost += w;
        }
    }

    cout << "Minimum total cost : " << totalCost << endl;

    return 0;
}

// why we use MST?
// 1. graph থেকে  Minimum Spaning Tree বের করার জন্য।
// 2. সব গুলো node কে connected রাখতে কম খরচে এবং totalCost  টা যাতে কম হয়।
// 3. Cycle Detect করে 