#include <bits/stdc++.h>
using namespace std;

int parent[105];

void inisialize(int sz)
{
    for (int i = 0; i < sz; i++)
    {
        parent[i] = -1;
    }
}

// find parent
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    else
    {
        // path compression
        int leader = dsu_find(parent[node]);
        return leader;
    }
}

void Union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    parent[leaderB] = leaderA;
}

int main()
{
    inisialize(5);

    Union(1, 2);
    Union(3, 4);
    // merge using leader 
    Union(1, 3);

    cout << dsu_find(2) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}