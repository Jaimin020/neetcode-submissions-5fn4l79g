class Solution {
public:
    bool check(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
    bool checkInclusion(string s1, string s2) {
        int xsum = 0;
        int xwin = 0;
        for(int i=0;i<s1.size();i++) {
            xsum ^= s1[i];
            xwin ^= s2[i];
        }
        cout<<xsum<<endl;
        int n = s2.size();
        for(int i=s1.size();i<n;i++) {
            cout<<i<<"->"<<xwin<<endl;
            if (xsum == xwin && check(s1,s2.substr(i-s1.size(),s1.size()))) {
                return true;
            } else {
                xwin ^= s2[i-s1.size()];
                xwin ^= s2[i];
            }
        }
        cout<<s2.size()<<"->"<<xwin<<endl;
        if (xsum == xwin && check(s1,s2.substr(s2.size()-s1.size(),s1.size()))) {
            return true;
        }

        return false;

    }
};
