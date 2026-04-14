class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        int tar = abs(nums[0]*3);
        cout<<tar<<endl;
        int x = abs(nums[0]);
        for(int i=0;i<n;i++)
        {
            nums[i] = nums[i]+x;
        }
        for(int i=0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]+nums[i]<tar) {
                    j++;
                } else if (nums[j]+nums[k]+nums[i]>tar) {
                    k--;
                } else if (nums[j]+nums[k]+nums[i]==tar) {
                    ans.insert({nums[i]-x,nums[j]-x,nums[k]-x});
                    j++;
                    k--;
                } else {
                    break;
                }
            }
        }
        vector<vector<int>> fans;
        for(auto e:ans)
        {
            fans.push_back(e);
        }
        return fans;
    }
};
