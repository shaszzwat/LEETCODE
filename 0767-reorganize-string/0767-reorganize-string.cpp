class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        vector<int> freq(26, 0);

        for(char c : s) freq[c-'a']++;

        for(int i = 0; i < 26; i++) {
            if(freq[i]) pq.push({freq[i], char('a'+i)});
        }

        string ans = "";
        pair<int,char> prev = {0, '#'};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ans += curr.second;
            curr.first--;

            if(prev.first > 0) pq.push(prev);

            prev = curr;
        }

        return ans.size() == s.size() ? ans : "";
    }
};