class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> lo(26);
        vector<int>ans;

        for(int i = 0; i<s.size(); i++){

            lo[s[i]- 'a']=i;

        }
        int i = 0;
        while(i<s.size()){
            int start = i;
            int end = lo[s[start] - 'a'];
            while(start <= end)
            {
                end = max(end, lo[s[start] - 'a']);
                start++;

            }
            ans.push_back(end-i+1);
            i = end+1;
        }

        return ans;
        
    }
};