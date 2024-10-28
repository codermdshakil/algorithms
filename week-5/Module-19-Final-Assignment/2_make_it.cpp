#include <bits/stdc++.h>
using namespace std;

bool canReach(int X)
{
    queue<int> q;
    unordered_set<int> visited;

    q.push(1);
    visited.insert(1);

    // BFS loop
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == X)
        {
            return true;
        }

        if (current + 3 <= X && visited.find(current + 3) == visited.end())
        {
            q.push(current + 3);
            visited.insert(current + 3);
        }

        if (current * 2 <= X && visited.find(current * 2) == visited.end())
        {
            q.push(current * 2);
            visited.insert(current * 2);
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X;
        cin >> X;

        // call can reach cundtion 
        if (canReach(X))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
