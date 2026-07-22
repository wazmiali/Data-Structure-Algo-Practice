class Solution {
public:

    void traverse(TreeNode* root, vector<int> & result){
        if(root){
            traverse(root->left, result);
            traverse(root->right, result);
            result.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;

    }
};