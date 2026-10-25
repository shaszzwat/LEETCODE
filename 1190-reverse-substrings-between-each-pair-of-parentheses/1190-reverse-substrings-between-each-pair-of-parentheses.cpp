class Solution {
public:
    string reverseParentheses(string s) {
        vector<pair<int,int>> v;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                int count = 1;

                for(int j = i + 1; j < s.size(); j++) {
                    if(s[j] == ')') count--;
                    if(s[j] == '(') count++;

                    if(count == 0) {
                        v.push_back({i, j});
                        break;
                    }
                }
            }
        }

       
        for(int i = v.size() - 1; i >= 0; i--) {
            reverse(s.begin() + v[i].first + 1,
                    s.begin() + v[i].second);
        }

        string ans = "";

        for(char ch : s) {
            if(ch != '(' && ch != ')') {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};