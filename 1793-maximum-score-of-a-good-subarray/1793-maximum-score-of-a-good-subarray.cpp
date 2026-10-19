class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int curr=k;
        int n=nums.size();
        int mini=nums[k];
        int next=k+1;
        int prev=k-1;
        int score=nums[k];
        while(next<n && prev>=0){
            if(nums[next]>=nums[prev]){
                mini=min(mini,nums[next]);
                next++;
                score=max(score,mini*(next-prev-1));
            }
            else{
                mini=min(mini,nums[prev]);
                prev--;
                score=max(score,mini*(next-prev-1));
            }
        }

        while(next<n){
            mini=min(mini,nums[next]);
            next++;
            score=max(score,mini*(next-prev-1));
        }
         while(prev>=0){
            mini=min(mini,nums[prev]);
            prev--;
            score=max(score,mini*(next-prev-1));
        }
        return score;


        
    }
};