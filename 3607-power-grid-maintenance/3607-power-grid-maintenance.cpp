class Solution {
public:
    vector<int> parent, Rank;

    int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
    }

    void Union(int x, int y) {
        x = findp(x);
        y = findp(y);

        if (x == y) return;

        if (Rank[x] < Rank[y])
            swap(x, y);

        parent[y] = x;

        if (Rank[x] == Rank[y])
            Rank[x]++;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        parent.resize(c + 1);
        Rank.assign(c + 1, 0);

        for (int i = 1; i <= c; i++)
            parent[i] = i;

        for (auto &e : connections)
            Union(e[0], e[1]);

        
        unordered_map<int, set<int>> comp;

        for (int i = 1; i <= c; i++) {
            comp[findp(i)].insert(i);
        }

        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = findp(x);

            if (type == 1) {
                if (comp[root].count(x))
                    ans.push_back(x);
                else {
                    if (comp[root].empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(*comp[root].begin());
                }
            }
            else {
                comp[root].erase(x);
            }
        }

        return ans;
    }
};