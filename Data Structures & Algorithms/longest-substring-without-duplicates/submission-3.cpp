class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.size();
        if(!n) return 0;
        unordered_set<char> us;
        int ans = 1;
        while(i<=j && j<n)
        {
            if(us.find(s[j])==us.end()) {
                us.insert(s[j]);
                j++;
            } else {
                ans = max(ans,j-i);
                us.erase(s[i]);
                i++;
            }
        }
        return max(ans,j-i);
    }
};
