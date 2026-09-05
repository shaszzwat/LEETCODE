class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        
        int ans=0;
        for(int i=0;i<word.size();i++){
            int j=i+1;
            int count=1;
            while(j<word.size() && abs(word[j]-word[i])<=1){
                count++;
                i++;j++;

                

            }
            if(count!=1){
                ans+=count/2;
            }

        }
       
        return ans;
        
    }
};