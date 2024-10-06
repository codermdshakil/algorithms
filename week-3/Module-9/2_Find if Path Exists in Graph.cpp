// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    vector<int> v[200005];
    bool visit[200005];

    void dfs(int s){
        visit[s] = true;
        for(auto child:v[s]){
         if(!visit[child]){
            dfs(child);
         }   
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < edges.size(); i++) {

            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(source);
        return visit[destination];
    }
};

