#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[301][301];
    int solve(vector<int>& nums , int l , int r ){
        if(l > r)return 0;
        if(dp[l][r] != -1)return dp[l][r];
        int ans = INT_MIN;
        for(int k = l ; k <= r ; k++){
            int temp = (nums[l-1] * nums[r + 1] * nums[k]) +  (solve(nums , l , k - 1) + solve(nums,k+1,r));
            ans = max(temp , ans);
        }
        return dp[l][r] = ans;
        
    }
    int maxCoins(vector<int>& nums) {
        
        vector<int> arr;
        memset(dp , -1 , sizeof(dp));
        arr.push_back(1);
        arr.insert(arr.end() , nums.begin() , nums.end());
        arr.push_back(1);

        return solve(arr , 1 , nums.size() );
    }
};
