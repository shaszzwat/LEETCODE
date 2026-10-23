
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr) return true;

        if(a == nullptr || b == nullptr) return false;

        if(a->val != b->val) return false;

        return check(a->left, b->right) &&
               check(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return check(root->left, root->right);
    }
};
