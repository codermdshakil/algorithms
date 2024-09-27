#include <bits/stdc++.h>
using namespace std;

// graph to store matrix elements
char graph[1001][1001];

// visited mat to check item visited or not
bool visit[1001][1001];

// to move x wais
int dx[4] = {-1, 0, 1, 0};

// to move y wais
int dy[4] = {0, 1, 0, -1};

// take row and col input
int n, m;

// check index are valid or not
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m && graph[ci][cj] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

// dfs traversal
void dfs(int si, int sj)
{
    visit[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i]; // children row
        int cj = sj + dy[i]; // children col

        // check valid index and visit false
        if (visit[ci][cj] == false && valid(ci, cj) == true)
        {
            dfs(ci, cj);
            visit[ci][cj] = true;
        }
    }
}

int main()
{
    // take row and col input
    cin >> n >> m;

    // take input of matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    // store count of apartments
    int counting_apartmetn = 0;

    // country count logic
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check country has and not visited and valid(i, j) == true [optional]
            if (graph[i][j] == '.' && visit[i][j] == false )
            {
                dfs(i, j);
                counting_apartmetn++;
            }
        }
    }

    cout << counting_apartmetn << endl;

    return 0;
}