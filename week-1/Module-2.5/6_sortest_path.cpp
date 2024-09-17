#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];
int level[1005];
int parents[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // Traverse all children of the current node (parent)
        for (auto child : v[parent])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[parent] + 1;
                parents[child] = parent;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;

    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));
    memset(parents, -1, sizeof(parents));

    // Run BFS from the source node
    bfs(src);

    // Trace back the path from destination to source
    int x = des;
    vector<int> shortest_path;
    
    // Start from the destination and trace back to the source
    while (x != -1)
    {
        shortest_path.push_back(x);
        x = parents[x];  // This will trace the correct path using the parents array
    }

    // Reverse the path to print from source to destination
    reverse(shortest_path.begin(), shortest_path.end());

    // Print the shortest path
    for (auto val : shortest_path)
    {
        cout << val << " ";
    }

    return 0;
}
