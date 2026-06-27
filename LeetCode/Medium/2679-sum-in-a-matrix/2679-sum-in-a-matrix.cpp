class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        
        vector<priority_queue<int>> pq(n);

        for (int i = 0; i < n; i++) {
            for (int x : nums[i]) {
                pq[i].push(x);
            }
        }

        int sum = 0;

        for (int i = 0; i < m; i++) {
            int mx = 0;

            for (int j = 0; j < n; j++) {
                mx = max(mx, pq[j].top());
                pq[j].pop();
            }

            sum += mx;
        }

        return sum;
    }
};