class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        if(n==1) return h[0];
        vector<int> fromRight(n,0);
        vector<int> fromLeft(n,0);

        fromRight[n-1] = n;
        fromLeft[0] = -1;

        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {
                st.pop();
            }
            if(st.empty()) {
                fromRight[i] = n;
            }
            else {
                fromRight[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        st1.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st1.empty() && h[i]<=h[st1.top()])
            {
                st1.pop();
            }
            if(st1.empty()) {
                fromLeft[i] = -1;
            }
            else {
                fromLeft[i] = st1.top();
            }
            st1.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            cout<<fromRight[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<fromLeft[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            ans = max(ans,((fromRight[i]-1)-fromLeft[i])*h[i]);
        }
        return ans;
    }
};
