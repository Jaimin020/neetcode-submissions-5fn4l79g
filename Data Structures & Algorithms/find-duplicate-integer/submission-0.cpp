class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::bitset<10001> bs;
        for(int i=0;i<nums.size();i++) {
            if(bs[nums[i]]) {
                return nums[i];
            }
            bs[nums[i]] = 1;
        }
        return -1;
    }
};
