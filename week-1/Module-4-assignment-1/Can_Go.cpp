#include <bits/stdc++.h>
using namespace std;

// graph to store matrix elements
char graph[1001][1001];

// to check visited or not
bool visit[1001][1001];

// store input of row and col
int n, m;

// valid index or not check function
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m && graph[ci][cj] == '.')
    {
        return true;
    }
    else if (graph[ci][cj] == 'A' || graph[ci][cj] == 'B')
    {
        return true;
    }
    else
    {
        return false;
    }
}

// to move x wise
int dx[4] = {-1, 0, 1, 0};

// to move y wise
int dy[4] = {0, 1, 0, -1};

void dfs(int si, int sj)
{
    visit[si][sj] = true;

    // get children
    for (int i = 0; i < 4; i++)
    {
        //  childrens
        int ci = si + dx[i];
        int cj = sj + dy[i];

        if (visit[ci][cj] == false && valid(ci, cj))
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
            cin >> graph[i][j];
        }
    }

    dfs(1, 2); // source node

    // check can go or not
    if (visit[2][6] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}