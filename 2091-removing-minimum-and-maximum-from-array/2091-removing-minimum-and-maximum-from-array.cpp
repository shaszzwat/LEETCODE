class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int smalli=-1;
        int bigi=-1;
        int small=INT_MAX;
        int big=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<small){
                smalli=i;
                small=nums[i];
            }
            if(nums[i]>big){
                bigi=i;
                big=nums[i];
            }
        }
        int n=nums.size();

        int front=max(bigi+1,smalli+1);
        int back=max(n-smalli,n-bigi);
        int both=min(bigi+1,smalli+1)+min(n-smalli,n-bigi);

        return min({front,back,both});
        
    }
};