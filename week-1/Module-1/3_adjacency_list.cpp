#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // create adjacency list using vector
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // [ this line should command if the graph is diracted]
    }

    // 1 print adjacency list
    // for (int x : mat[0])
    // {
    //     cout << x << " ";
    // }

    // 2 print adjacency list
    // for (int i = 0; i < mat[0].size(); i++)
    // {
    //     cout << mat[0][i] << " ";
    // }

    // print all adjacency list
    for (int i = 0; i < n; i++)
    {
        for (int x : mat[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * Summary
 * কোন node এর সাথে কে কে connected  তা বের করার জন্য Adjacency list ব্যাবহার করা হয় ।
 * */