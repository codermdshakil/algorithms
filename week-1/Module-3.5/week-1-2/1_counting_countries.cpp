#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool visit[1001];

void dfs(int src)
{
    cout << src << endl;
    visit[src] = true;
    for (auto child : v[src])
    {
        if (visit[child] == false)
        {
            dfs(child);
            visit[child] = true;
        }
    }
}

int main()
{

    return 0;
}
