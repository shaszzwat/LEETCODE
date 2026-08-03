class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n==1){
            return{};
        }
        vector<string>ans;
        for(int i=1;i<n;i++){
            string s=to_string(i);
            string a=""+s+"/";


            for(int j=2;j<=n;j++){
                if(i<j)
                {string b=to_string(j);
                if(gcd(i,j)==1){
                   ans.push_back(a+b);
                }}





            }
        }
        return ans;
        
    }
};