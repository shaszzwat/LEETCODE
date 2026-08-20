class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        
        priority_queue<pair<double, pair<int,int>>> pq;

        for(auto &c : classes) {
            int p = c[0];
            int t = c[1];

            double gain = (double)(p + 1) / (t + 1)
                        - (double)p / t;

            pq.push({gain, {p, t}});
        }

        while(extraStudents--) {

            auto top = pq.top();
            pq.pop();

            int p = top.second.first;
            int t = top.second.second;

            
            p++;
            t++;

            
            double gain = (double)(p + 1) / (t + 1)
                        - (double)p / t;

            pq.push({gain, {p, t}});
        }

        double ans = 0;

        while(!pq.empty()) {
            int p = pq.top().second.first;
            int t = pq.top().second.second;

            ans += (double)p / t;

            pq.pop();
        }

        return ans / classes.size();
    }
};