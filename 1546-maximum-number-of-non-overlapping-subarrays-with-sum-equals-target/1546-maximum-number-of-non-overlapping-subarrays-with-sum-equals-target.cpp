class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        mpp[0] = -1;
        int last = -1;  
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int req = nums[i] - target;

            if (mpp.find(req) != mpp.end() && mpp[req] >= last) {
                count++;
                last = i;
            }

            
            if (i >= last)
                mpp[nums[i]] = i;
        }

        return count;
    }
};