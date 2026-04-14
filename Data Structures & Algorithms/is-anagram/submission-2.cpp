class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> aCou(26,0);

        for(int i=0;i<n;i++)
        {
            aCou[s[i]-'a']++;
        }
        for(int j=0;j<m;j++)
        {
            aCou[t[j]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(aCou[i]!=0) return false;
        }
        return true;
    }
};
