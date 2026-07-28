class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrice) {
        int n=stockPrice.size();
        if(n<=2){
            return (n==1)?0:1;
        }
        sort(stockPrice.begin(),stockPrice.end());
        int line=1;
        int delx=stockPrice[1][0]-stockPrice[0][0];
        int dely=stockPrice[1][1]-stockPrice[0][1];
        for(int i=2;i<n;i++){
            int newdelx=stockPrice[i][0]-stockPrice[i-1][0];
            int newdely=stockPrice[i][1]-stockPrice[i-1][1];
            if(1LL*newdely*delx!=1LL*newdelx*dely){
                line++;
            }
            delx=newdelx;
            dely=newdely;
        }
        return line;

        
    }
};