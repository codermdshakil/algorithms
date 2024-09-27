#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool visit[1001][1001];
int n, m;

int dx[4] = {-1, 0, 1, 0}; // row move
int dy[4] = {0, 1, 0, -1}; // coloum move

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m  && graph[ci][cj] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int si, int sj)
{
    visit[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i]; // children row
        int cj = sj + dy[i]; // children colum

        if (visit[ci][cj] == false && valid(ci, cj) == true )
        {
            visit[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    dfs(0,0);

    // chech which matrix items i can visit

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << visit[i][j];
        }
        cout << endl;
    }

    return 0;
}
