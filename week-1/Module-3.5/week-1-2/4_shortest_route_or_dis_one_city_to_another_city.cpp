#include <bits/stdc++.h>
using namespace std;

// graph to store matrix elements
char graph[1001][1001];

// visited mat to check item visited or not
bool visit[1001][1001];

// store level
int level[1001][1001];

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
    level[si][sj] = 0;

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
            if (visit[ci][cj] == false && valid(ci, cj) == true)
            {
                visit[ci][cj] = true;
                level[ci][cj] = level[row][col] + 1;
                q.push({ci, cj});
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

    
    // take source row, col input
    int source_row, source_col;
    cin >> source_row >> source_col;

    // take destination row, col input
    int destination_row, destination_col;
    cin >> destination_row >> destination_col;

    bfs(source_row, source_col); // source node

    if (visit[destination_row][destination_col] == true)
    {
        cout << "Shortest route  or dis : " << level[destination_row][destination_col] << endl;
    }
    else
    {
        cout << "Jawya jabe na" << endl;
    }
 

    return 0;
}