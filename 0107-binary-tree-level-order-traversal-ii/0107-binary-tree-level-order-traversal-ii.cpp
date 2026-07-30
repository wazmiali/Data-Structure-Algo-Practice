class Solution {
public:
    int numberOfLevel(TreeNode *root){
        if(!root)
            return 0;
        return 1 + max(numberOfLevel(root->left), numberOfLevel(root->right));

    }
    void levelTraversal(TreeNode * root, vector<vector<int>> &arr, int level){
        if(!root)
            return;
        arr[level].push_back(root->val);
        levelTraversal(root->left, arr, level + 1);
        levelTraversal(root->right, arr, level + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        int level = numberOfLevel(root);
        vector<vector<int>> final_ans(level);
        levelTraversal(root, final_ans, 0);
        reverse(final_ans.begin(), final_ans.end());
        return final_ans;
        
    }
};