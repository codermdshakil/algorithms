#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];

vector<int> level_values;

void bfs(int src, int input_level)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    visit[src] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int parent = p.first;
        int level = p.second;

        if (level == input_level)
        {
            level_values.push_back(parent);
        }

        for (auto child : v[parent])
        {
            if (visit[child] == false)
            {
                q.push({child, level + 1});
                visit[child] = true;
            }
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
    int input_level;
    cin >> input_level;
    memset(visit, false, sizeof(visit));

    bfs(0, input_level);

    reverse(level_values.begin(), level_values.end());
    for (auto val : level_values)
    {
        cout << val << " ";
    }

    return 0;
}