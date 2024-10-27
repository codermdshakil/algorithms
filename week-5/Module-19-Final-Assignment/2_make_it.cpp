#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// implement BFS with set
bool canReach(ll input_value)
{
    queue<ll> q;
    // use set don't work for same number
    set<ll> vis;

    q.push(1);
    vis.insert(1);

    while (!q.empty())
    {
        ll current_value = q.front();
        q.pop();

        if (current_value == input_value)
        {
            return true;
        }

        ll first = current_value + 3;
        ll second = current_value * 2;

        if (first <= input_value && vis.find(first) == vis.end())
        {
            q.push(first);
            vis.insert(first);
        }

        if (second <= input_value && vis.find(second) == vis.end())
        {
            q.push(second);
            vis.insert(second);
        }
    }

    return false;
}

int main()
{
    // testcase
    int t;
    cin >> t;
    while (t--)
    {
        // take input value
        ll input;
        cin >> input;
        bool flag = canReach(input);
        if (flag)
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
