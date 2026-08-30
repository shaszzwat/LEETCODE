class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];

            if(curr <= k && k % curr == 0) {
                int currlcm = nums[i];

                for(int j = i; j < nums.size(); j++) {
                    currlcm = lcm(currlcm, nums[j]);

                    if(currlcm == k) {
                        count++;
                    }
                    else if(k % currlcm != 0) {
                        break;
                    }
                }
            }
        }

        return count;
    }
};