class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int token=0;
        int maxtoken=0;
        while(i<=j){
            if(power>=tokens[i]){
                power=power-tokens[i];
                token++;
                maxtoken=max(token,maxtoken);
                i++;
            }
            else if(token>0){
                token--;
                power+=tokens[j];
                j--;

            }
            else{
                break;
            }
        }
        return maxtoken;
        
    }
};