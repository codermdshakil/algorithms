#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    // create adjaccency matrix
    int mat[n][n];

    // inisialise using value 0 of all cell
    memset(mat, 0, sizeof(mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    //  check all values if 1 that means connected otherwise not connected
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    if (mat[2][4] == 1)
    {
        cout << "Connected Ache" << endl;
    }
    else
    {
        cout << "Connected Nai" << endl;
    }

    return 0;
}