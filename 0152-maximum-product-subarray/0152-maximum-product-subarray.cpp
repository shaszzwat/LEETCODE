class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi=INT_MIN;
        int n=nums.size();
        long long cummul=1;
        for(int i=0;i<n;i++){
            if(cummul==0){
                cummul=1;
            }
            cummul=cummul*nums[i];
            maxi=max(maxi,cummul);

        }
        cummul=1;
        for(int i=n-1;i>=0;i--){
            if(cummul==0){
                cummul=1;
            }
            cummul=cummul*nums[i];
            maxi=max(maxi,cummul);

        }
        return (int)maxi;
        
    }
};