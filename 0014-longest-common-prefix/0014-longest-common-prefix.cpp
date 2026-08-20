class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            bool flag = false;

            for(int j = 0; j < min(pre.size(), strs[i].size()); j++) {
                if(pre[j] == strs[i][j]) {
                    continue;
                }
                else {
                    pre = pre.substr(0, j);
                    flag = true;
                    break;
                }
            }

            
            if(!flag) {
                pre = pre.substr(0, min(pre.size(), strs[i].size()));
            }

            
            if(pre.empty())
                return "";
        }

        return pre;
    }
};