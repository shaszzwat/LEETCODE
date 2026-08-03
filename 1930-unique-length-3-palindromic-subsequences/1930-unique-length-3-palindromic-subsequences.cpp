class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c);
            int last = s.rfind(c);

            if (first == -1 || first == last)
                continue;

            unordered_set<char> mid;

            for (int i = first + 1; i < last; i++) {
                mid.insert(s[i]);
            }

            ans += mid.size();
        }

        return ans;
    }
};