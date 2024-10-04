#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2,1}, {-2,-1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
bool visit[10][10];
int dis[10][10];
int n, m;


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

        // cout << par.first << " " << par.second << endl;

        // take children
        for (int i = 0; i < 8; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) == true && visit[ci][cj] == false)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        n = 8, m = 8;
        string s, d;
        cin >> s >> d;
        int si, sj, di, dj;
        si = s[0] - 'a';
        sj = s[1] - '1';
        di = d[0] - 'a';
        dj = d[1] - '1';

        memset(visit, false, sizeof(visit));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << endl;

    }

    return 0;
}