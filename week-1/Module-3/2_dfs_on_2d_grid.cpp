#include <bits/stdc++.h>
using namespace std;

char a[20][20];
bool visit[20][20];

// to move right left up down
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

// create a function to check source index valid or not
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
void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    visit[si][sj] = true;

    // take source childrens right, left, up, down
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && visit[ci][cj] == false)
        {
            dfs(ci, cj);
            visit[ci][cj] = true;
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
            cin >> a[i][j];
        }
    }

    // take source input
    int si, sj;
    cin >> si >> sj;

    memset(visit, false, sizeof(visit));

    dfs(si, sj);

    return 0;
}