#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // create matrix
    int mat[n][n];

    // inisial value of mat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = -1;
            }
        }
    }

    // take mat input
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }

    // print mat values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}