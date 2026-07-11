class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<int, vector<int>, greater<int>> pql;
        priority_queue<int, vector<int>, greater<int>> pqr;

        int n = costs.size();
        vector<bool> visited(n, false);

        if (2 * candidates >= n) {
            sort(costs.begin(), costs.end());
            long long sum = 0;
            for (int i = 0; i < k; i++)
                sum += costs[i];
            return sum;
        }

       
        for (int i = 0; i < candidates; i++) {
            visited[i] = true;
            pql.push(costs[i]);
        }

        int l = candidates;

        
        int r = n - 1;
        for (int i = n - 1; i >= n - candidates; i--) {
            visited[i] = true;
            pqr.push(costs[i]);
            r = i;
        }
        r--;

        long long res = 0;

        while (k--) {

            if (pql.empty()) {
                res += pqr.top();
                pqr.pop();

                while (r >= 0 && visited[r]) r--;

                if (r >= 0) {
                    visited[r] = true;
                    pqr.push(costs[r]);
                    r--;
                }
                continue;
            }

            if (pqr.empty()) {
                res += pql.top();
                pql.pop();

                while (l < n && visited[l]) l++;

                if (l < n) {
                    visited[l] = true;
                    pql.push(costs[l]);
                    l++;
                }
                continue;
            }

            int a = pql.top();
            int b = pqr.top();

            if (a <= b) {
                res += a;
                pql.pop();

                while (l < n && visited[l]) l++;

                if (l < n) {
                    visited[l] = true;
                    pql.push(costs[l]);
                    l++;
                }
            } else {
                res += b;
                pqr.pop();

                while (r >= 0 && visited[r]) r--;

                if (r >= 0) {
                    visited[r] = true;
                    pqr.push(costs[r]);
                    r--;
                }
            }
        }

        return res;
    }
};