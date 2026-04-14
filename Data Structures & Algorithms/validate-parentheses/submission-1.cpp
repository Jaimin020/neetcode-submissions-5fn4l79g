class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        int n = str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(' || str[i]=='[' || str[i]=='{')
            {
                s.push(str[i]);
            }
            else if(s.size()==0 || str[i]==')' && s.top()!='(')
            {
                return false;
            }
            else if(s.size()==0 || str[i]=='}' && s.top()!='{')
            {
                return false;
            }
            else if(s.size()==0 || str[i]==']' && s.top()!='[')
            {
                return false;
            }
            else if(s.size()>0)
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        if(s.size()==0) return true;
        return false;
    }
};
