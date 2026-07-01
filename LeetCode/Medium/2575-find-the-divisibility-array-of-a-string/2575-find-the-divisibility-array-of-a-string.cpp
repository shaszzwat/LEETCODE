class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>div(word.size());
        long long num=0;
        for(int i=0;i<word.size();i++){
            num=((num*10)+word[i]-'0')%m;
            if(num==0){
                div[i]=1;
            }
            else{
                div[i]=0;
            }

        }
        return div;
        
    }
};