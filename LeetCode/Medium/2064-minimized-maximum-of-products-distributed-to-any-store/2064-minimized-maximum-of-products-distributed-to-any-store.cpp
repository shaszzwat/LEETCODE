class Solution {
public:
    int bs(int low, int high, int n, vector<int>& quantities) {
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int stores = 0;
            for (int q : quantities) {
                stores += (q + mid - 1) / mid;   
            }

            if (stores <= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int mx = 0;
        for (int q : quantities) {
            mx = max(mx, q);
        }

        return bs(1, mx, n, quantities);
    }
};