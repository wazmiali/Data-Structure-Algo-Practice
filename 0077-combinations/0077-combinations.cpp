class Solution {
public:
    vector<vector<int>> ans;
    void helper(int val, int k , int n, vector<int>&v){

        if(v.size()==k){
            ans.push_back(v);
            return;
        }

        for(int i = val; i<=n; i++){
            v.push_back(i);
            helper(i+1,k,n,v);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k){
        vector<int>v;
        helper(1,k,n,v);
        return ans;
    }
    
};