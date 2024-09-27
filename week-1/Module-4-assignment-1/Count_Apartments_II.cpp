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
int dfs(int si, int sj)
{

    visit[si][sj] = true;
    int room_count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i]; // children row
        int cj = sj + dy[i]; // children col

        // check valid index and visit false
        if (visit[ci][cj] == false && valid(ci, cj) == true)
        {
            room_count += dfs(ci, cj);
            visit[ci][cj] = true;
        }
    }
    return room_count;
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

    // to store apartments values
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' && !visit[i][j])
            {
                int room_count = dfs(i, j);
                // get apartment values
                apartments.push_back(room_count);
            }
        }
    }

    if (apartments.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        // sort apartments value in assending order
        sort(apartments.begin(), apartments.end());

        for (int count : apartments)
        {
            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}