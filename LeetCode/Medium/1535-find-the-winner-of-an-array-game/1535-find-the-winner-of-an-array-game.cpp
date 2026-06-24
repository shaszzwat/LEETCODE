class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int a=0;
        
           a=*max_element(arr.begin(),arr.end());
        
        int n=arr.size();
        vector<int>won(n+1,0);
        int i=0;
        int j=1;
        while(i<n &&j<n){
            if(arr[i]>arr[j]){
                if(j<i){
                    j=i+1;
                    
                }
                else{
                    j++;
                }
                won[i]++;
                if(won[i]==k){
                    return arr[i];
                }
            }
            else{
                if(i<j){
                    i=j+1;
                }
                else{
                    i++;
                }
                won[j]++;
                if(won[j]==k){
                    return arr[j];
                }
            }
        }
        return a;

        
    }
};