class Solution {
public:
    string minWindow(string s, string t) {

        vector<int>f(256.0);
        int mini = 1e7;
        int ini = -1;
        for(int i=0; i<t.size(); i++)
        {
            f[t[i]]++;

        }
        int cnt = 0;
        int l = 0;
        int r = 0;
        while(r<s.size())
        {
            if(f[s[r]] > 0) cnt++;
            f[s[r]]--;
            while(cnt==t.size())
            {
                if(r-l<mini)
                {
                    mini = r-l;
                    ini = l;

                }
                f[s[l]]++;
                if(f[s[l]] >  0) cnt--;
                l++;
            }
            r++;
        }
        if(ini==-1) return "";
        return s.substr(ini,mini+1);
        
    }
};