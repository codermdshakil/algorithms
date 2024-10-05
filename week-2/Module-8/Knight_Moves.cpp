#include <bits/stdc++.h>
using namespace std;

// knight moves
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int visit[105][105];
int dis[105][105];
int n, m;

// valid index check
bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

// bfs traversal
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

        for (int i = 0; i < 8; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && !visit[ci][cj])
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
    // take testcase
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        // input source and destination
        int si, sj, qi, qj;
        cin >> si >> sj >> qi >> qj;

        // inisiall values
        memset(visit, false, sizeof(visit));
        memset(dis, -1, sizeof(dis));

        bfs(si, sj);

        // print result
        if (dis[qi][qj] == -1)
            cout << -1 << endl;  
        else
            cout << dis[qi][qj] << endl;
    }
    return 0;
}
