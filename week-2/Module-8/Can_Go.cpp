#include <bits/stdc++.h>
using namespace std;

const long long int N = 1005;
const long long int INF = INT_MAX;

// adjacency list with store 2 value 1. konta connected 2. cost
vector<pair<int, int>> v[N];

// distance array to store distance
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

// Dijkstra Obtimaized version
// time complexity - O(V+E) * log v  or  (ElogV);
void dijkstra_obtimaized(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.first;
        int parentCost = parent.second;

        // get childrens from parent
        for (pair<int, int> child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]}); // push children to queue
            }
        }
    }
}

int main()
{

    int n;
    long long int e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    // inisially distance array value infinite
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

   

    int src;
    cin >> src;

    dijkstra_obtimaized(src);
    
    int t;
    cin >> t;
    while (t--)
    {
        int des, maxCost;
        cin >> des >> maxCost;

        if (dis[des] <= maxCost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
