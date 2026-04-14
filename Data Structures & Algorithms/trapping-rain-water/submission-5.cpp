class Solution {
public:
    int trap(vector<int>& h) {
        int i = 0;
        int j = 1;
        int n = h.size();
        vector<int> vis(n,-1);

        int ans = 0;
        int temp = 0;
        while(j<n) {
            if(h[j]<h[i]) {
                temp+=(h[i]-h[j]);
                j++;
            } else {
                ans+=temp;
                temp=0;
                vis[j] = i;
                i=j;
                j=i+1;
            }
        }
        i = n-1;
        while(vis[i]!=-1)
        {
            i = vis[i];
        }
        j = i-1;
        temp = 0;
        while(j>=0) {
            if(h[j]<h[i]) {
                temp+=(h[i]-h[j]);
                j--;
            } else {
                ans+=temp;
                temp=0;
                while(vis[j]!=-1)
                {
                    j = vis[j];
                }
                i = j;
                j = i-1;
            }
        }
        
        return ans;   
    }
};
