class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> nCou;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nCou[nums[i]]==0)
            {
                nCou[nums[i]]++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
