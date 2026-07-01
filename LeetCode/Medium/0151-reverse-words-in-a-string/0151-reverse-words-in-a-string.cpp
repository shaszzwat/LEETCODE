class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string sen = "";

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == ' ' && st.empty()) {
                continue;
            }

            if (s[i] != ' ') {
                st.push(s[i]);
            }
            else {
                string word = "";
                while (!st.empty()) {
                    word += st.top();
                    st.pop();
                }

                sen += word;
                sen += ' ';
            }
        }

        
        if (!st.empty()) {
            string word = "";
            while (!st.empty()) {
                word += st.top();
                st.pop();
            }
            sen += word;
        }

        
        if (!sen.empty() && sen.back() == ' ')
            sen.pop_back();

        return sen;
    }
};