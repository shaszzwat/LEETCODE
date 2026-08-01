class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<long long>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v.insert(nums[i]);
            }
            
        }
        
        int j=1;
        for(auto it:v){
            if(it==j){
                j++;
                
            }
            else{
                return j;
            }
        }
        return j;
        
    }
};