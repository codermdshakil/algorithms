#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool visit[N];

// dfs traversal
void dfs(int src)
{
    cout << src << " ";
    visit[src] = true;
    for (auto child : v[src])
    {
        if (visit[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visit, false, sizeof(visit));

    dfs(0);

    return 0;
}