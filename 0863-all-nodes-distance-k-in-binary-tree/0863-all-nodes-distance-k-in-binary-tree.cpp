class Solution {
public:
    void parent(unordered_map<TreeNode*, TreeNode*>& mpp,
                TreeNode* root) {
        if (root == nullptr) return;

        if (root->left)
            mpp[root->left] = root;

        if (root->right)
            mpp[root->right] = root;

        parent(mpp, root->left);
        parent(mpp, root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        unordered_map<TreeNode*, int> visited;

        parent(mpp, root);

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = 1;

        int curr = 0;

        while (!q.empty() && curr < k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !visited[cur->left]) {
                    q.push(cur->left);
                    visited[cur->left] = 1;
                }

                if (cur->right && !visited[cur->right]) {
                    q.push(cur->right);
                    visited[cur->right] = 1;
                }

                if (mpp.count(cur) && !visited[mpp[cur]]) {
                    q.push(mpp[cur]);
                    visited[mpp[cur]] = 1;
                }
            }

            curr++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};