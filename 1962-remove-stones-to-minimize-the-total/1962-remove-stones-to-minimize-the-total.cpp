class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=accumulate(piles.begin(),piles.end(),0);
        priority_queue<int>q;
        for(int i=0;i<piles.size();i++){
            q.push(piles[i]);
        }
        for(int i=0;i<k;i++){
            int a=q.top();
            q.pop();
            sum=sum-a/2;
            q.push(a-a/2);

        }
        return sum;
        
    }
};