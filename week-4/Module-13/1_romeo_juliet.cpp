
// Problem Link::
// https://www.hackerrank.com/contests/phitron-monthly-programming-contest-a-batch-04-a-feb-2024/challenges/romeo-and-juliet-2
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// adjacency list
vector<int> v[N];
int dis[N];
bool visit[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;
    dis[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : v[parent])
        {
            if (!visit[child])
            {
                visit[child] = true;
                q.push(child);
                dis[child] = dis[parent] + 1;
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

    memset(visit, false, sizeof(visit));
    memset(dis, -1, sizeof(dis));

    int src, des, k;
    cin >> src >> des >> k;

    bfs(src);

    if (dis[des] != -1 && dis[des] <= k * 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
