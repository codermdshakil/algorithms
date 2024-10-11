
// Problem Link : https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll parents[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};

// dijkstra implementation
void dijkstra(ll s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();

        ll parentNode = parent.first;
        ll parentCost = parent.second;

        // get childrens from parent
        for (pi child : v[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                parents[childNode] = parentNode;
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
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        parents[i] = -1;
    }

    dijkstra(1);

    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        ll x = n;
        vector<ll> paths;
        while (x != -1)
        {
            // cout << x << " ";
            paths.push_back(x);
            x = parents[x];
        }

        reverse(paths.begin(), paths.end());

        for (ll path : paths)
        {
            cout << path << " ";
        }
        cout << "\n";
    }
    return 0;
}