class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(int i=0;i<moveTo.size();i++){
            
            
            mpp.erase(moveFrom[i]);
           
            mpp[moveTo[i]]++;
        }
        vector<int>ans;
        for(auto it:mpp){
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;

        
    }
};