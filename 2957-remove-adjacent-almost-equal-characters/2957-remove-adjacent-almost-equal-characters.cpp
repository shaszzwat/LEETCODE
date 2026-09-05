class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        vector<int>a;
        int ans=0;
        for(int i=0;i<word.size();i++){
            int j=i+1;
            int count=1;
            while(j<word.size() && abs(word[j]-word[i])<=1){
                count++;
                i++;j++;

                

            }
            if(count!=1){
                a.push_back(count);
            }

        }
        for(int i=0;i<a.size();i++){
            ans+=a[i]/2;
        }
        return ans;
        
    }
};