class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mpp;

        for(int x : nums)
            mpp[x]++;

        int ans = 1;

        if(mpp.count(1)){
            if(mpp[1] % 2)
                ans = max(ans, mpp[1]);
            else
                ans = max(ans, mpp[1] - 1);
        }

        for(auto it : mpp){
            long long curr = it.first;

            if(curr == 1) continue;

            int len = 0;

            while(mpp.count(curr)){
                if(mpp[curr] >= 2){
                    len += 2;
                    if(curr > 1e9 / curr) break;   
                    curr = curr * curr;
                }
                else{
                    len++;
                    break;
                }
            }

            if(len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};