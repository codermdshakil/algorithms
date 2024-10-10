#include <bits/stdc++.h>
using namespace std;
const int n = 100005;
int par[n];
int sz[n];
void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    par[node] = dsu_find(par[node]);
    return par[node];
}
void dsu_union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    if (leaderA == leaderB)
        return;
    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dsu_init(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
    }

    // finds leader and store
    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == -1)
        {
            leaders.push_back(i);
        }
    }

    // print leaders size why -1 ? because in two cities we need just one road if city is 2 then road should 1
    cout << leaders.size() - 1 << endl;

    // print road
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }
}
