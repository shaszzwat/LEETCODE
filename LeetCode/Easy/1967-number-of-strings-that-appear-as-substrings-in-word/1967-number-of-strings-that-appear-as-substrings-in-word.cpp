class Solution {
public:
    bool issub(string pattern, string &word) {
        for (int i = 0; i < word.size(); i++) {
            int j = 0;
            int k = i;

            while (j < pattern.size() && k < word.size() && pattern[j] == word[k]) {
                j++;
                k++;
            }

            if (j == pattern.size())
                return true;
        }
        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (int i = 0; i < patterns.size(); i++) {
            if (issub(patterns[i], word))
                count++;
        }
        return count;
    }
};