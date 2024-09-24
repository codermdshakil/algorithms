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

    // just for if i want to traverse both components then just use like this
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i);
            c++;
        }
    }

    cout << endl;
    // we can check how many component here
    cout << "Component - " << c << endl;

    return 0;
}