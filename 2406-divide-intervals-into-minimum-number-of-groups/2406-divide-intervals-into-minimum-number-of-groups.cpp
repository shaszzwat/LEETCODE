class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for (int i = 0; i < intervals.size(); i++) {
            v.push_back({intervals[i][0], 1});
            v.push_back({intervals[i][1], -1});
        }
        sort(v.begin(), v.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first == b.first)
                     return a.second > b.second;
                 return a.first < b.first;
             });
        int count=0;
        int ans=1;
        for(int i=0;i<v.size();i++){
            count+=v[i].second;
            ans=max(ans,count);

        }
        return ans;
    }
};