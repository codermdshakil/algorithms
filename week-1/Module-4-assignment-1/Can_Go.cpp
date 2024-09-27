#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool visit[1001][1001];
int n, m;

// Valid index check function
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
    {
        return (graph[ci][cj] == '.' || graph[ci][cj] == 'A' || graph[ci][cj] == 'B');
    }
    return false;
}

// to move x wise
int dx[4] = {-1, 0, 1, 0};

// to move y wise
int dy[4] = {0, 1, 0, -1};

// dfs traversal funcition
void dfs(int si, int sj)
{
    visit[si][sj] = true;

    // get childrens
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];

        // check valid and not visited
        if (valid(ci, cj) && !visit[ci][cj])
        {
            dfs(ci, cj);
            visit[ci][cj] = true;
        }
    }
}

int main()
{
    cin >> n >> m;

    // store room a and b
    pair<int, int> roomA, roomB;

    // Input the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];

            // input room A
            if (graph[i][j] == 'A')
            {
                roomA = {i, j};
            }

            // input room B
            if (graph[i][j] == 'B')
            {
                roomB = {i, j};
            }
        }
    }

    dfs(roomA.first, roomA.second);

    // Print output

    if (visit[roomB.first][roomB.second])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
