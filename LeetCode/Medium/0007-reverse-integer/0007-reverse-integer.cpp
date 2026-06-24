class Solution {
public:
    int reverse(long x) {
        long a;
        a=0;
        long  x1;

        

        if (x<0){
            x1=-x;
        }
        else{
            x1=x;
        }
        
        
        while(x1>0){
            if((a>INT_MAX/10)||(a<INT_MIN)/10){
            return 0;
            }
            a=a*10+x1%10;
            x1=x1/10;
        }
        
        if(x<0){
            return -a;
        }
        else{
            return a;
        }
        
    }
};