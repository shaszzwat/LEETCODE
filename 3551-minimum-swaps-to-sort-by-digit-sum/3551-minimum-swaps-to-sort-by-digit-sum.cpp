class Solution {
public:
    int minSwaps(vector<int>& nums) {

        vector<pair<pair<int,int>,int>> nums2;

        for(int i = 0; i < nums.size(); i++) {

            int x = nums[i];
            int sum = 0;

            while(x > 0) {
                sum += x % 10;
                x /= 10;
            }

            nums2.push_back({{sum, nums[i]}, i});
        }

        sort(nums2.begin(), nums2.end());

        int n = nums.size();
        vector<bool> vis(n, false);

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(vis[i] || nums2[i].second == i)
                continue;

            int cnt = 0;
            int j = i;

            while(!vis[j]) {
                vis[j] = true;
                j = nums2[j].second;
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};