#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool visit[1005][1005];
int dis[1005][1005];
char grid[1005][1005];
pair<int, int> parent[1005][1005];

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int a = par.first;
        int b = par.second;

        // take children
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && visit[ci][cj] == false && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a, b};
            }
        }
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    if (visit[di][dj])
    {
        // 1. print jawya jabe kina
        cout << "YES\n";
        // 2. print distance
        cout << dis[di][dj] << endl;
        // 3. print moves
        pair<int, int> p = {di, dj};
        vector<pair<int, int>> path;
        while (!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }

        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        // print moves
        string ans = "";
        for (int i = 1; i < path.size(); i++)
        {
            // row same
            if (path[i - 1].first == path[i].first)
            {
                // R/L
                if (path[i - 1].second + 1 == path[i].second)
                {
                    ans += "R";
                }
                else
                {
                    ans += "L";
                }
            }
            else
            {
                // U/D
                if (path[i - 1].first + 1 == path[i].first)
                {
                    ans += "D";
                }
                else
                {
                    ans += "U";
                }
            }
        }
        cout << ans << " ";
    }

    else
    {
        cout << "NO\n";
    }
    return 0;
}