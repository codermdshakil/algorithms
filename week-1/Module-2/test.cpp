#include <bits/stdc++.h>
using namespace std;

// gloval adjacency list
vector<int> v[1005];

// track visited or not
bool visit[1005];

void bsf(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for (auto child : v[parent])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // push values to adjacency list
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src;

    // visit all value inisially false
    memset(visit, false, sizeof(visit));

    bsf(src);

    return 0;
}