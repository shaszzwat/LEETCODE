class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> st;

        for(int x : nums) {
            if(x % k == 0) st.push_back(x);
        }

        sort(st.begin(), st.end());

        int expected = k;

        for(int x : st) {
            if(x == expected) {
                expected += k;
            } else if(x > expected) {
                return expected;
            }
        }

        return expected;
    }
};