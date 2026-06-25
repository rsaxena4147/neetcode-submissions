class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int i = 0;
        int j = i+1;
        while(j < nums.size()){
            if(nums[i] == nums[j])return true;
            i++;
            j++;
        }
        return false;
    }
};