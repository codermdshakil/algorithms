#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N];

// size array to size
int group_size[N];

// level array to store level
int level[N];

// inisially parent all values are -1 that means everyone is Leader
void dsu_inisialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    // path compression
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

// dsu union by level or rank
// time complexity - constant
void dsu_union_by_level(int node1, int node2)
{

    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    // small level will be sacrifice
    if (level[leaderA] > level[leaderB])
    {
        // small group leader is big group
        par[leaderB] = leaderA;
        // dont increase level
    }
    else if (level[leaderB] > level[leaderA])
    {
        // small group leader is big group
        par[leaderA] = leaderB;
        // dont increase level
    }
    else{
        // both group are same then
        // that means equal 
        par[leaderA] = leaderB;
        level[leaderB]++; // increase level one
    }
}

int main()
{

    dsu_inisialize(7);
    
    // group 1
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);

    // group 2
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);

    dsu_union_by_level(1,4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}

