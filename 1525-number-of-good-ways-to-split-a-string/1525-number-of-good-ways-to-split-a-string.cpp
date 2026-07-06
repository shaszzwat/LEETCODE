class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>left;
        unordered_map<char,int>right;
        int n=s.size();
        vector<int>lefty(n);
        vector<int>righty(n);
        for(int i=0;i<s.size();i++){
            left[s[i]]++;
            lefty[i]=left.size();
        }
        for(int i=n-1;i>=0;i--){
            right[s[i]]++;
            righty[i]=right.size();
        }
        int count=0;

        for(int i=0;i<n-1;i++){
            if(lefty[i]==righty[i+1]){
                count++;
            }
        }
        return count;


        
    }
};