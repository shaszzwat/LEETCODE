class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int>mpp;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]++;
                count++;
                int j=i+1;
                while(j<s.size() && mpp.find(s[j])!=mpp.end()){
                    i++;
                    j++;
                }
            }

        }
        return count;


        
    }
};