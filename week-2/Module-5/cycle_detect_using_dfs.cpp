#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visit[N];
int parentArray[N];
bool ans;

void dfs(int parent)
{
    visit[parent] = true;
    // cout << parent << " ";

    for (int child : adj[parent])
    {
        // cycle detect  logic
        if (visit[child] == true && parentArray[parent] != child)
        {
            ans = true;
        }
        if (visit[child] == false)
        {
            parentArray[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // take values
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // inisial values
    memset(visit, false, sizeof(visit));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    // called bfs using 0 - n-1 value
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }

     // print output
    if (ans)
    {
        cout << "Cycle Found" << endl;
    }
    else
    {
        cout << "Cycle Not Found" << endl;
    }

    return 0;
}