#include <bits/stdc++.h>
using namespace std;

int parent[105];
int level[105];

void inisialize(int sz)
{
    for (int i = 0; i < sz; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}

// find parent
int dsu_find(int node)
{
    cout << "Calling node " << node << endl;
    if (parent[node] == -1)
    {
        return node;
    }
    else
    {
        // path compression
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}

// void Union(int node1, int node2)
// {
//     int leaderA = dsu_find(node1);
//     int leaderB = dsu_find(node2);
//     parent[leaderB] = leaderA;
// }

// union using level
void Union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        parent[leaderA] = leaderB;
    }
    else
    {
        parent[leaderB] = leaderA;
        level[leaderA]++; // increase level size one
    }
}

int main()
{
    inisialize(7);

    // Union(1, 2);
    // Union(3, 4);
    // // merge using leader
    // Union(1, 3);

    // cout << dsu_find(2) << endl;
    // cout << dsu_find(4) << endl;

    Union_by_level(6, 7);
    Union_by_level(5, 6);
    Union_by_level(4, 5);
    Union_by_level(3, 4);
    Union_by_level(2, 3);
    Union_by_level(1, 2);

    cout << "+++++++++++++++++++++++++++" << endl;
    cout << dsu_find(7) << endl;
    cout << "############################" << endl;
    cout << dsu_find(6) << endl;
    cout << "############################" << endl;
    cout << dsu_find(5) << endl;
    cout << "############################" << endl;
    cout << dsu_find(4) << endl;
    cout << "############################" << endl;
    cout << dsu_find(3) << endl;
    cout << "############################" << endl;
    cout << dsu_find(2) << endl;
    cout << "############################" << endl;
    cout << dsu_find(1) << endl;
    cout << "############################" << endl;

    return 0;
}