#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // create a matrix
    int mat[n][n];
    vector<pair<int, int>> edgeLists;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1 && i != j)
            {
                edgeLists.push_back({i, j});
            }
        }
    }

    for (pair<int, int> child : edgeLists)
    {
        cout <<  child.first << " " << child.second <<endl;
    }

    return 0;
}