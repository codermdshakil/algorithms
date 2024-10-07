#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N];

// inisially parent all values are -1 that means everyone is Leader
void dsu_inisialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    par[1] = 2;
    par[2] = 3;
    par[5] = 6;
    par[6] = 7;
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

void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1); // 3
    int leaderB = dsu_find(node2); // 7

    // leaderA sacrifice his leaderness and leaderA parent is leaderB. Altemately both node leader is leaderB
    par[leaderA] = leaderB;
}

int main()
{
    dsu_inisialize(8);
    dsu_union(1, 5); // sent here two nodes root value

    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;
    cout << dsu_find(5) << endl;
    cout << dsu_find(6) << endl;
    cout << dsu_find(7) << endl;
    

    return 0;
}