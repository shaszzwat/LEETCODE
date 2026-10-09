class Solution {
public:
    int minInsertions(string s) {
        string n = "";
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                n.push_back(s[i]);
            }
            else if (i < s.size() - 1 && s[i] == ')' && s[i + 1] == ')') {
                n.push_back(')');
                i++;
            }
            else {
                count++;
                n.push_back(')');
            }
        }

        int open = 0;

        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '(') {
                open++;
            }
            else if (open > 0) {
                open--;
            }
            else {
                count++;
            }
        }

        count += open * 2;

        return count;
    }
};