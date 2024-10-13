#include <bits/stdc++.h>
using namespace std;

char a[50][50];
int dis[50][50];
bool visit[50][50];
pair<int, int> parents[50][50];
vector<pair<int, int>> path;
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// Check if the coordinates are within the grid
bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m && a[ci][cj] != '#');
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> p;
    p.push({si, sj});
    visit[si][sj] = true;
    dis[si][sj] = 0;
    parents[si][sj] = {-1, -1}; // Root has no parent

    while (!p.empty())
    {
        pair<int, int> par = p.front();
        p.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if (valid(ci, cj) && !visit[ci][cj])
            {
                p.push({ci, cj});
                visit[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
                parents[ci][cj] = {par.first, par.second}; // Store the parent coordinates
            }
        }
    }
}

void printPath(int di, int dj)
{
    // If destination has no valid path, print "No path"
    if (!visit[di][dj])
    {
        cout << "No path" << endl;
        return;
    }

    pair<int, int> current = {di, dj};

    // Trace back from destination to source using the parent array
    while (current != make_pair(-1, -1))
    {
        path.push_back(current);
        current = parents[current.first][current.second];
    }

    // Reverse the path to get it from source to destination
    reverse(path.begin(), path.end());

    // // Print the path
    // cout << "Path from source to destination:" << endl;
    // for (auto p : path)
    // {
    //     cout << "(" << p.first << ", " << p.second << ")" << " ";
    // }
    // cout << endl;
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;

    // Input the matrix and store the source 'R' and destination 'D'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);
    printPath(di, dj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto p : path)
            {
                if (p.first == i && p.second == j)
                {
                    a[i][j] = 'X';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "";
        }
        cout << endl;
    }

    return 0;
}
