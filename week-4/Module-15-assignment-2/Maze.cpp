#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;
char grid[N][N];
int dis[N][N];
bool visited[N][N];
pair<int, int> parent[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && (grid[x][y] == '.' || grid[x][y] == 'D');
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i].first;
            int ny = y + d[i].second;

            if (isValid(nx, ny) && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
                parent[nx][ny] = {x, y}; 
            }
        }
    }
}

// replace path using X
void markPath(int di, int dj, int si, int sj)
{
    int x = di, y = dj;
    while (!(x == si && y == sj))
    {
        grid[x][y] = 'X';
        pair<int, int> path = parent[x][y];
        int px = path.first;
        int py = path.second;
        x = px;
        y = py;
    }
    grid[si][sj] = 'R';
    grid[di][dj] = 'D';
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(dis, -1, sizeof(dis));
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    // bfs traversal
    bfs(si, sj);

    if (visited[di][dj])
    {
        markPath(di, dj, si, sj);
    }

    // print output 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
