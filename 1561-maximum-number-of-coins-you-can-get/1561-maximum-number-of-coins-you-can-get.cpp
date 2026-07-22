class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0;
        int n=piles.size();
        int count=n/3;
        int i=n-2;
        while(count--){
            sum+=piles[i];
            i=i-2;
        }
        return sum;
        
    }
};