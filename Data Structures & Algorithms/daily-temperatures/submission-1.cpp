class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        int n = temp.size();
        s.push(n-1);
        vector<int> ans(n,0);
        ans[n-1] = 0;
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && temp[s.top()]<=temp[i])
            {
                s.pop();
            }

            ans[i] = (s.empty()?0:(s.top()-i));
            s.push(i);
        }
        return ans;
    }
};
