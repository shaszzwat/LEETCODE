class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> cost(n + 1, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        q.push({0, k});
        cost[k] = 0;

        while(!q.empty()){

            auto it = q.top();
            q.pop();

            int cost1 = it.first;
            int node = it.second;

            for(auto edge : adj[node]){

                int nextNode = edge.first;
                int weight = edge.second;

                if(cost1 + weight < cost[nextNode]){
                    cost[nextNode] = cost1 + weight;
                    q.push({cost[nextNode], nextNode});
                }
            }
        }

        int maxi = 0;

        for(int i = 1; i <= n; i++){
            if(cost[i] == 1e9)
                return -1;

            maxi = max(maxi, cost[i]);
        }

        return maxi;
    }
};