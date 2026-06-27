class Solution {
public:
    bool isPos(vector<int>&nums , int k , int h){
        int count = 0;
        for(int n : nums){

            int hour = ceil(n*1.0 / k);

            count+= hour;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        

        long long low = 1;
        long high = *max_element(nums.begin() , nums.end() );
        int ans = -1;
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(isPos(nums , mid , h)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
