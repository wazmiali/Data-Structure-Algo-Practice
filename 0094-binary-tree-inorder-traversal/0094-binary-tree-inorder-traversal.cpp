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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        while(1){
            if(st.empty() && root == NULL) return v;
            if(root==NULL){
                TreeNode* t=st.top();
                v.push_back(t->val);
                root=t->right;
                st.pop();
                continue;
            }
            st.push(root);
            root = root->left;
        }
        return v;        
    }
};