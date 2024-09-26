#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

bool visit[1005];

// bsf travere
void bsf(int src, int des)
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
            if (level == 1 || level == 0)
            {
                paise = true;
            }
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
    if (paise == false)
    {
        cout << "NO" << endl;
    }
    else
    {

        cout << "YES" << endl;
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
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(visit, false, sizeof(visit));
        bsf(src, des);
    }

    return 0;
}