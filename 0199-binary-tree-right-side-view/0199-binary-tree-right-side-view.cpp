/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root ==nullptr){
            return{};
        }
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v1;
            int s=q.size();
            for(int i=0;i<s;i++){
                v1.push_back(q.front()->val);
                if(q.front()->left !=nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right !=nullptr){
                    q.push(q.front()->right);
                }
                q.pop();


            }
            v.push_back(v1);
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i][v[i].size()-1]);
        }
        return ans;
        
    }
};