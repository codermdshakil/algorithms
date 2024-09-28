#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

bool visit[N];
int parentArray[N];

bool ans;

void dfs(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << " ";

        for (int child : adj[parent])
        {
            // cycle deteck logic

            if (visit[child] == true && parentArray[parent] != child)
            {
                ans = true;
            }
            if (visit[child] == false)
            {
                q.push(child);
                parentArray[child] = parent;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visit, false, sizeof(visit));
    memset(parentArray, -1, sizeof(parentArray));

    // inisially ans false
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }

    if(ans){
        cout << "Cycle Found" << endl;
    }
    else{
        
        cout << "Cycle not Found" << endl;
    }

    return 0;
}