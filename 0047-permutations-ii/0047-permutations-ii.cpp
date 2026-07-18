class Solution {
public:
    set<vector<int>> st;
    int n;
    vector<int> visited;

    void solve(vector<int>& nums, vector<int>& v, int idx) {
        if (idx == n) {
            st.insert(v);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                continue;
            }

            v.push_back(nums[i]);
            visited[i] = 1;

            solve(nums, v, idx + 1);

            v.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        visited.assign(n, 0);

        vector<int> temp;
        solve(nums, temp, 0);

        vector<vector<int>> ans;
        for (auto &it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};