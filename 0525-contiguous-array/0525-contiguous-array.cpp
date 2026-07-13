class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        unordered_map<int,int>mpp;
        int maxi=0;
        int cumsum=0;

        for(int i=0;i<nums.size();i++){
            cumsum+=nums[i];
            if(cumsum==0){
                maxi=max(maxi,i+1);
            }
            if(mpp.find(cumsum)!=mpp.end()){
                maxi=max(maxi,i-mpp[cumsum]);
            }
            else{
                mpp[cumsum]=i;
            }
        }
        return maxi;

        
    }
};