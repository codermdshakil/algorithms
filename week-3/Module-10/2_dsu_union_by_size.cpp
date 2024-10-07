#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N];

// size array to size
int group_size[N];

// inisially parent all values are -1 that means everyone is Leader
void dsu_inisialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

// find who is leader and return leader
// time Complexity - O(logN) better then O(N)

int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }

    // Path compression
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}


// Union by size
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    // small size of group will be sacrifice
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        // update group size
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        // update group size
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    dsu_inisialize(7);
    
    // group 1
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);

    // group 2
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);

    dsu_union_by_size(1,4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}