class Solution {
public:
    int count = 0;

    void dfs(int i,
             vector<int>& visited,
             unordered_map<int, vector<pair<int,int>>>& mpp) {

        visited[i] = 1;

        for (auto it : mpp[i]) {
            int next = it.first;
            int dir = it.second;

            if (visited[next] == -1) {
                count += dir;
                dfs(next, visited, mpp);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        unordered_map<int, vector<pair<int,int>>> mpp;

        for (auto &e : connections) {
            int u = e[0];
            int v = e[1];

            mpp[u].push_back({v, 1});
            mpp[v].push_back({u, 0});
        }

        vector<int> visited(n, -1);

        dfs(0, visited, mpp);

        return count;
    }
};