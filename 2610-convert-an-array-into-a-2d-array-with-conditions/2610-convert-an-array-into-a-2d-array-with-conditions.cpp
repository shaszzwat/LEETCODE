class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>hash(201,0);
        for(auto it:nums){
            hash[it]++;
        }
        vector<int>zero(201,0);
        vector<vector<int>>ans;
        while(hash!=zero){
            vector<int>v;
            for(int i=0;i<201;i++){
                if(hash[i]>0){
                    v.push_back(i);
                    hash[i]--;
                }
            }
            ans.push_back(v);
        }
        return ans;
        
        
    }
};