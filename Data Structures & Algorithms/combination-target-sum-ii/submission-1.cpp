class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, int target, vector<int>& temp) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0)return;
        if(i >= nums.size())return;

        for(int j = i ; j < nums.size() ; j++){
            if(j > i && nums[j] == nums[j-1])continue;

            temp.push_back(nums[j]);
            solve(nums , j + 1, target - nums[j] , temp);
            temp.pop_back();
        }

        //solve(nums , i+1 , target , temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, 0, target, temp);
        return ans;
    }
};
