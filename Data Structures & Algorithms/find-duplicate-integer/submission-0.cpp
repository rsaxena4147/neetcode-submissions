class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     //   return 0;
        int slow = 0;
        int fast = 0;

        do{
            fast = nums[nums[fast]];;
            slow = nums[slow];
        }while(slow != fast);

        slow = 0;
       
        while(true){
            if(slow == fast)return slow;
            slow = nums[slow];
            fast = nums[fast];
        };

        return -1;
    }
};
