class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>>diff;
        int n=costs.size();
        int sum=0;
        for(int i=0;i<costs.size();i++){
            diff.push_back({costs[i][1]-costs[i][0],i});
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n/2;i++){
            sum+=costs[diff[i].second][1];
        }
         for(int i=n/2;i<n;i++){
            sum+=costs[diff[i].second][0];
        }
        return sum;
        
    }
};