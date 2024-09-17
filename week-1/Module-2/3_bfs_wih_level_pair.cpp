#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

bool visit[1005];

// bsf travere
void bsf(int src, int des)
{
    // pair first is value second is level
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

        // cout << parent << " ";
        if (parent == des)
        {
            cout << des << " " << "level is : " << level << endl;
            paise = true;
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
        // push to adjacency list
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src;

    // set inisial values false of visit array
    memset(visit, false, sizeof(visit));

    bsf(src, 4);

    return 0;
}