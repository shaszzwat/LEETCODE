class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long low = 1;
        long long high = 1000000;
        long long ans = LLONG_MAX;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long apples = 2LL * mid * (mid + 1) * (2 * mid + 1);

            if (apples >= neededApples) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans * 8;
    }
};