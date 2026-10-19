
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto it : words) {
            mpp[it]++;
        }

        vector<pair<int,string>> v;
        for(auto it : mpp) {
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), [](pair<int,string> a, pair<int,string> b) {
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
