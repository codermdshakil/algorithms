#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    int adjeccency_matrix[n][n];

    memset(adjeccency_matrix, 0, sizeof(adjeccency_matrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjeccency_matrix[a][b] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adjeccency_matrix[a][b] == 1)
        {
            cout << "YES" << endl;
        }
        else if (a == b)
        {
            cout << "YES" << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
    }

    return 0;
}