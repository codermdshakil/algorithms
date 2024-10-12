#include <bits/stdc++.h>
using namespace std;

char a[50][50];
int dis[50][50];
bool visit[50][50];
int n;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> p;
    p.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;

    while (!p.empty())
    {
        pair<int, int> par = p.front();
        p.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if (valid(ci, cj) && !visit[ci][cj] && a[ci][cj] != 'T')
            {
                p.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        int si, sj, di, dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(visit, false, sizeof(visit));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << endl;
    }

    return 0;
}