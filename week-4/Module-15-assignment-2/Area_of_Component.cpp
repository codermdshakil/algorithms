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

// bfs traversal on 2d matrix
int bfs(int si, int sj)
{
    // create a queue to store values
    queue<pair<int, int>> q;

    q.push({si, sj});
    visit[si][sj] = true;
    int component_count = 1;

    while (!q.empty())
    {
        // ber kora
        pair<int, int> node = q.front();
        q.pop();

        int row = node.first;
        int col = node.second;

        // kaj kora
        // cout << first << " " << second << endl;

        // children push kora
        for (int i = 0; i < 4; i++)
        {
            int ci = row + dx[i]; // children row
            int cj = col + dy[i]; // children col

            // check valid index and visit false
            if (valid(ci, cj) == true && visit[ci][cj] == false && graph[ci][cj] != '-')
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                component_count++;
            }
        }
    }
    return component_count;
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

    int min_component_size = INT_MAX;
    bool found_component = false;

    // country count logic
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check country has and not visited
            if (visit[i][j] == false && graph[i][j] == '.')
            {
                int component_size = bfs(i, j);
                min_component_size = min(min_component_size, component_size);
                found_component = true;
            }
        }
    }

    // print output
    if (found_component)
    {
        cout << min_component_size << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}