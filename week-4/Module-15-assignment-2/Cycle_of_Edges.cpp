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

int main()
{
    int n, e;
    cin >> n >> e;

    // callded dsu initialize function for inisialize
    dsu_initialize(n);
    int cycleCount = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        // leaderA and leaderB is Equal that means here is cycle
        if (leaderA == leaderB)
        {
            cycleCount++;
        }
        else
        {
            dsu_union_by_size(a, b);
        }
    }

    cout << cycleCount <<endl;

    return 0;
}