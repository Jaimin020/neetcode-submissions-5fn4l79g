class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]] = true;
        }

        for(int i=0;i<n;i++)
        {
            if(m.find(nums[i]-1)!=m.end())
            {
                m[nums[i]] = false;
            }
        }

        int cou = 0;
        for(auto e:m)
        {
            if(e.second==true)
            {
                int j=0;
                int tem = 0;
                while(m.find(e.first+j)!=m.end())
                {
                    j++;
                    tem++;
                }
                cou = max(cou,tem);
            }
        }
        return cou;
    }
};
