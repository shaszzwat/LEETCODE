class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsD) {
        map<int, int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        int g = numsD[0];

        for (int i = 1; i < numsD.size(); i++) {
            g = gcd(g, numsD[i]);
        }

        int count = 0;

        for (auto it : mpp) {
            if (g % it.first == 0) {
                return count;
            }
            count += it.second;
        }

        return -1;
    }
};