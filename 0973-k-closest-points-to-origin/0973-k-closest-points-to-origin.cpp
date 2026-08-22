class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > pq;

        for(int i = 0; i < points.size(); i++){

            long long x = points[i][0];
            long long y = points[i][1];

            pq.push({x*x + y*y, {points[i][0], points[i][1]}});
        }

        vector<vector<int>> ans;

        for(int i = 0; i < k; i++){

            ans.push_back({
                pq.top().second.first,
                pq.top().second.second
            });

            pq.pop();  
        }

        return ans;
    }
};