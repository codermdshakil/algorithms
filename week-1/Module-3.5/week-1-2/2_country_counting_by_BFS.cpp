#include <bits/stdc++.h>
using namespace std;

// graph to store matrix elements
char graph[1001][1001];

// visited mat to check item visited or not
bool visit[1001][1001];
int dis[1001][1001];

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
void bfs(int si, int sj)
{
    // create a queue to store values
    queue<pair<int, int>> q;

    q.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        // ber kora
        pair<int, int> p = q.front();
        q.pop();

        int first = p.first;
        int second = p.second;

        // kaj kora
        // cout << first << " " << second << endl;

        // children push kora
        for (int i = 0; i < 4; i++)
        {
            int ci = first + dx[i]; // children row
            int cj = second + dy[i]; // children col

            // check valid index and visit false
            if (visit[ci][cj] == false && valid(ci, cj) == true)
            {
                q.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[first][second] + 1;
            }
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
 
    // store count of country
    int country_count = 0;

    // country count logic
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check country has and not visited
            if (graph[i][j] == '.' && visit[i][j] == false)
            {
                // called bfs traversal
                bfs(i, j);
                country_count++;
            }
        }
    }

    cout << country_count << endl;

    return 0;
}