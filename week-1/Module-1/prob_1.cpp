#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    // create a mat using n
    int mat[n][n];
    // insial all value 0
    memset(mat, 0, sizeof(mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // ajdacency matrix using to check between 2 node connected or not 
    if (mat[0][4] == 1)
    {
        cout << "Connected Ache" << endl;
    }
    else
    {
        cout << "Connected Nai" << endl;
    }

    return 0;
}