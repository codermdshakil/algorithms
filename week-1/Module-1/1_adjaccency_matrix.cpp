#include <bits/stdc++.h>
using namespace std;

int main()
{

    // n means size of node
    // e means size of edge

    int n, e;
    cin >> n >> e;

    // create a adjaccenct matric using  n size
    int adjeccency_matrix[n][n];

    // inisially matrix value set 0
    // memset(name_of_variable/name_of_matrix, inisial_value, sizeof(name_of_variable/name_of_matrix));
    memset(adjeccency_matrix, 0, sizeof(adjeccency_matrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjeccency_matrix[a][b] = 1;
        adjeccency_matrix[b][a] = 1; // [if direacted graph then this line should command]
    }

    // check all if value 1 then connected if 0 then not connected
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << adjeccency_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // check a specific node that is connected or not
    if (adjeccency_matrix[2][4] == 1)
    {
        cout << "Yes! Connected" << endl;
    }
    else
    {

        cout << "Not Connected" << endl;
    }

    return 0;
}