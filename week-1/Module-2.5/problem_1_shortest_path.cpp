#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];
int parents[1005];

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visit[src] = true;

    bool paise = false;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int parent = p.first;
        int level = p.second;

        if (parent == des)
        {
            cout << level << endl;
            paise = true;
        }

        for (auto child : v[parent])
        {
            if (visit[child] == false)
            {
                q.push({child, level + 1});
                visit[child] = true;
                parents[child] = parent;
            }
        }
    }
    if (paise == false)
    {
        cout << -1 << endl;
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

    int num;
    cin >> num;

    while (num--)
    {
        memset(visit, false, sizeof(visit));
        memset(parents, false, sizeof(parents));
        int src, des;
        cin >> src >> des;
        bfs(src, des);
    }

    return 0;
}