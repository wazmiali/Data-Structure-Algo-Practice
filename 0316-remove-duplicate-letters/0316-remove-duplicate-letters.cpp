class Solution {
public:
    string removeDuplicateLetters(string s) {

        int last[26];
        bool seen[26] = {};

        for(int i=0; i<s.size(); i++)
            last[s[i] - 'a'] = i;

            string ans;

            for(int i=0; i<s.size(); i++){
                char c = s[i];

                if(seen[c - 'a'])
                    continue;

                while(!ans.empty() &&
                ans.back() > c &&
                last[ans.back() - 'a'] > i){

                    seen[ans.back() - 'a'] = false;
                    ans.pop_back();
                }

                ans.push_back(c);
                seen[c - 'a'] = true;
            }

            return ans;
        
    }
};