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
    par[1] = 3;
    par[2] = 1;
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

int main()
{
    dsu_inisialize(4);
    cout << dsu_find(0) << endl;
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;

    return 0;
}