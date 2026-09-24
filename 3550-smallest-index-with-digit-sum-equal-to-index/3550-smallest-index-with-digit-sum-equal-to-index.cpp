class Solution {
public:
    int digsum(int x){
        int org=x;
        int sum=0;
        while(org>0){
            sum+=org%10;
            org=org/10;

        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digsum(nums[i])==i){
                return i;
            }
        }
        return -1;
        
    }
};