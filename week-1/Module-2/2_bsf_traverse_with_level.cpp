#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

bool visit[1005];

// level array to store level
int level[1005];

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

    int src;
    cin >> src;

    // set inisial values false of visit array
    memset(visit, false, sizeof(visit));

    // set inisial values -1 of level array
    memset(level, -1, sizeof(level));

    bsf(src);

    // print level 
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    

    return 0;
}