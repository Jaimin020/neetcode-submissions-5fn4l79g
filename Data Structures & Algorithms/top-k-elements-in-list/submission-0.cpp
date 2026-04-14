class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> cou;
        int n = nums.size();
        int maxCou = 0;
        for(int i=0;i<n;i++)
        {
            cou[nums[i]]++;
            maxCou = max(maxCou,cou[nums[i]]);
        }
        vector<vector<int>> cidx(maxCou+1);

        for(auto e:cou)
        {
            cidx[e.second].push_back(e.first);
        }
        vector<int> ans;
        for(int i=maxCou;i>=0;i--)
        {
            for(int j=0;j<cidx[i].size();j++)
            {
                ans.push_back(cidx[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
