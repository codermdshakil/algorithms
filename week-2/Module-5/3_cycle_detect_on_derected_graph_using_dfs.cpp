#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visit[N];
bool pathVisit[N];
bool ans;

void dfs(int parent)
{
    visit[parent] = true;
    pathVisit[parent] = true;
    for (int child : adj[parent])
    {
        // Cycle detect logic
        if(pathVisit[child] == true){
            ans = true;
        }
        if (!visit[child])
        {
            dfs(child);
        }
    }
    // kaj shes
    pathVisit[parent] =false;
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
    }

    // inisial values
    memset(visit, false, sizeof(visit));
    memset(pathVisit, false, sizeof(pathVisit));
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