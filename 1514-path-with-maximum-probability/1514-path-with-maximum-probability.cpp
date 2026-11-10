class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<double> v(n, 0);

        priority_queue<pair<double,int>> pq;

        unordered_map<int, vector<pair<int,double>>> mpp;

        for(int i = 0; i < edges.size(); i++) {
            mpp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mpp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        pq.push({1.0, start_node});
        v[start_node] = 1;

        while(!pq.empty()) {

            int node = pq.top().second;
            double pro = pq.top().first;
            pq.pop();

            
            

            for(auto it : mpp[node]) {

                double prob = it.second;
                int nextn = it.first;

                if(pro * prob > v[nextn]) {

                    v[nextn] = pro * prob;
                    pq.push({v[nextn], nextn});
                }
            }
        }

        return v[end_node];
    }
};