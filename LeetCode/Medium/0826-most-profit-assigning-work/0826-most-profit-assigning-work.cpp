class Solution {
public:
    int bs(int n, vector<pair<int,int>>& v){

        int low = 0;
        int high = v.size() - 1;
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(v[mid].first <= n){
                ans = v[mid].second;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>> v;
        int n = profit.size();

        for(int i = 0; i < n; i++){
            v.push_back({difficulty[i], profit[i]});
        }

        sort(v.begin(), v.end());

    
        for(int i = 1; i < n; i++){
            v[i].second = max(v[i].second, v[i-1].second);
        }

        int total = 0;

        for(int i = 0; i < worker.size(); i++){
            total += bs(worker[i], v);
        }

        return total;
    }
};