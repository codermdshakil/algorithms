#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    int adjacency_matirx[n][n];
    memset(adjacency_matirx, 0, sizeof(adjacency_matirx));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjacency_matirx[a][b] = 1;
        adjacency_matirx[b][a] = 1;
    }

     if (adjacency_matirx[2][4] == 1)
    {
        cout << "Yes! Connected" << endl;
    }
    else
    {

        cout << "Not Connected" << endl;
    }




    return 0;
}