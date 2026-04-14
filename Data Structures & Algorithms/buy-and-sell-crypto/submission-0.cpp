class Solution {
public:
    int maxProfit(vector<int>& p) {
        int i=0;
        int j=1;
        int n=p.size();

        int ans = 0;
        while(j<n)
        {
            if(p[i]>p[j]) {
                i=j;
                j=i+1;
            } else {
                ans = max(ans, p[j]-p[i]);
                j++;
            }
        }
        return ans;
    }
};
