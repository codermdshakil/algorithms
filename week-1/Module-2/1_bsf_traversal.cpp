#include <bits/stdc++.h>
using namespace std;

// gloval adjacency list
vector<int> v[1005];

// visit array to tack which node ar visited

bool visit[1005];

// bsf (breath search first) to traverse graph values
void bsf(int src)
{
    // create a queue
    queue<int> q;
    q.push(src);

    // then visit src true
    visit[src] = true;

    while (!q.empty())
    {
        // front ber kora
        int parent = q.front();
        q.pop();

        // kaj kora bsf value print
        cout << parent << " ";

        // children gula queue te push kora
        for (auto child : v[parent])
        {
            // if not visited then push it to queue
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

    // take input
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // take sources
    int src;
    cin >> src;

    // inisially visite all value false
    memset(visit, false, sizeof(visit));

    cout << "BSF level wise print : " ;
    bsf(src);
    return 0;
}