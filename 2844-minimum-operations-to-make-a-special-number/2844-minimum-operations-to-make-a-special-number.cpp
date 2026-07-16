class Solution {
public:
    int minimumOperations(string num) {

        int n = num.size();
        string s=num;
        if(s.size()>=2){
             if (((s[n - 1] == '0') && (s[n - 2] == '0' || s[n - 2] == '5')) ||
            ((s[n - 1] == '5') && (s[n - 2] == '2' || s[n - 2] == '7'))){
                return 0;
            }
        }

       
            vector<int> zero(num.size(), 0);
        vector<int> five(num.size(), 0);
        bool zeroo = false;
        bool found0 = false;
        bool found5 = false;
        for (int i = n - 1; i >= 0; i--) {
            if (found0) {
                break;
            }
            if (num[i] == '0') {
                zeroo = true;
                for (int j = i - 1; j >= 0; j--) {
                    if (num[j] == '5' || num[j] == '0') {
                        zero[i] = 1;
                        zero[j] = 1;
                        found0 = true;
                        break;
                    }
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (found5) {
                break;
            }
            if (num[i] == '5') {
                for (int j = i - 1; j >= 0; j--) {
                    if (num[j] == '2' || num[j] == '7') {
                        five[i] = 1;
                        five[j] = 1;
                        found5 = true;
                        break;
                    }
                }
            }
        }

        int c1 = 0;
        int curr = 0;
        int c2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (zero[i] == 1) {
                curr++;
                if (curr == 2) {
                    break;
                }
            } else {
                c1++;
            }
        }
        curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (five[i] == 1) {
                curr++;
                if (curr == 2) {
                    break;
                }
            } else {
                c2++;
            }
        }
        if (!found0 && !found5 && !zeroo) {
            return num.size();
        }
        if (found0 && found5) {
            return min(c1, c2);
        }
        if (found0) {
            return c1;
        }
        if (found5) {
            return c2;
        }
        if (zeroo) {
            return n - 1;
        }
        return 0;
    }
};