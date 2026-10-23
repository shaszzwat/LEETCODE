
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> mpp;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int level = q.front().second.first;
            int height = q.front().second.second;
            q.pop();

            mpp[level][height].insert(curr->val);

            if(curr->left != nullptr) {
                q.push({curr->left, {level - 1, height + 1}});
            }

            if(curr->right != nullptr) {
                q.push({curr->right, {level + 1, height + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it : mpp) {
            vector<int> v;

            for(auto q : it.second) {
                for(auto x : q.second) {
                    v.push_back(x);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};
