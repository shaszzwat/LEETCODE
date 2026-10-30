class Solution {
public:
    bool solve(vector<int>& val, int i, int n) {
        if(n == 0) return true;
        if(n < 0 || i == val.size()) return false;

        
        bool take = solve(val, i + 1, n - val[i]);

    
        bool notTake = solve(val, i + 1, n);

        return take || notTake;
    }

    bool checkPowersOfThree(int n) {
        vector<int> val;

        int x = 1;
        while(x <= n) {
            val.push_back(x);
            x *= 3;
        }

        return solve(val, 0, n);
    }
};