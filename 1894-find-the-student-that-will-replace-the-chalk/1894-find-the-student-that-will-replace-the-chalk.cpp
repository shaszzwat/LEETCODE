class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        if(k>=sum){
            k=k%sum;
        }
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }
            else{
                k=k-chalk[i];
            }
        }
        return 0;
    }
};