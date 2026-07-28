class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int op=0;
        if(mpp.size()==nums.size()){
            return 0;
        }
        for(int i=0;i<nums.size();i=i+3){
            for(int j=i;j<min((int)nums.size(),i+3);j++){
                mpp[nums[j]]--;
                if(mpp[nums[j]]==0){
                    mpp.erase(nums[j]);
                }

            }
            op++;
            if(mpp.size()==nums.size()-i-3){
                return op;
            }
        }
        return op;
        
    }
};