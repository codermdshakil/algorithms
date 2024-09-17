#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

bool visit[1005];

// level array to store level
int level[1005];

int parents[1005];

// bsf travere
void bsf(int src)
{
    queue<int> q;
    q.push(src);

    visit[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << " ";

        for (auto child : v[parent])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[parent] + 1;
                parents[child] = parent;
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
        // push to adjacency list
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;

    // set inisial values false of visit array
    memset(visit, false, sizeof(visit));

    // set inisial values -1 of level array
    memset(level, -1, sizeof(level));

    // parents inisial all value -1
    memset(parents, -1, sizeof(parents));

    bsf(src);

    // shortest path printing

    vector<int> sorted_path;

    int x = des;
    while (x != -1)
    {
        // cout << x << " ";
        sorted_path.push_back(x);
        x = parents[x];
    }

    // reverse sorted_path
    reverse(sorted_path.begin(), sorted_path.end());

    for (auto val : sorted_path)
    {
        cout << val << " ";
    }

    return 0;
}