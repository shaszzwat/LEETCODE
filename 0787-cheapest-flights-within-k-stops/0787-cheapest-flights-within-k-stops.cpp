class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> cost(n, INT_MAX);

        queue<pair<int, pair<int,int>>> q;

        cost[src] = 0;
        q.push({0, {0, src}});

        while(!q.empty()){

            int stop = q.front().first;
            int cost1 = q.front().second.first;
            int node = q.front().second.second;

            q.pop();

            for(auto it : adj[node]){

                if(stop <= k && cost1 + it.second < cost[it.first]){

                    cost[it.first] = cost1 + it.second;

                    q.push({
                        stop + 1,
                        {cost[it.first], it.first}
                    });
                }
            }
        }

        if(cost[dst] == INT_MAX)
            return -1;

        return cost[dst];
    }
};