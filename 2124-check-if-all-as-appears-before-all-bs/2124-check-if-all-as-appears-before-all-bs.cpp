class Solution {
public:
    bool checkString(string s) {
        int a=0;
        int b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' && b>0){
                return false;
            }
            if(s[i]=='a'){
                a++;
            }
            else{
                b++;
            }
        }
        return true;
        
    }
};