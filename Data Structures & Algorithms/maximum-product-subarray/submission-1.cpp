class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int mini = 1;
        int maxi = 1;

        for(int i = 0 ; i < nums.size() ; i++){


            int temp = min({nums[i] , mini * nums[i] , nums[i] * maxi});
            
            maxi = max({nums[i] , mini * nums[i] , nums[i] * maxi});
            mini = temp;
            ans = max({ans , maxi, mini});

        }
        return ans;
    }
};
