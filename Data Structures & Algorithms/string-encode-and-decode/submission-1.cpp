class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ens = "";
        for(int i=0;i<n;i++)
        {
            string del = "#";
            del += to_string(strs[i].size());
            del += "#";
            ens += del;
            ens += strs[i];

        }
        return ens;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        int i = 0;
        while(i<n)
        {
            int len = 0;
            string cou = "";
            if(s[i]=='#')
            {
                i++;
                while(s[i]!='#')
                {
                    cou+=s[i];
                    i++;
                }
                len = stoi(cou);
                i++;
            }
            string tem = "";
            for(int j=0;j<len;j++)
            {
                tem += s[i];
                i++;
            }
            ans.push_back(tem);
        }
        return ans;
    }
};
