class Solution {
public:
    vector<vector<int>> output;
    void solve(vector<int>& nums , int i , vector<int>& temp , int target , int sum){

        if(i >= nums.size() && sum == target){
            output.push_back(temp);
            return;

        }
        if(i >= nums.size())return;
        if(sum > target)return;

        
            temp.push_back(nums[i]);
            solve(nums , i , temp , target , sum + nums[i]);
            temp.pop_back();
        

        solve(nums , i +1 , temp , target , sum);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(nums , 0 , temp , target , 0);

        return output;
    }
};
