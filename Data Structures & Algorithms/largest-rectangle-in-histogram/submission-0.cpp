class Solution {
   public:
    vector<int> left(vector<int>& nums) {
        vector<int> ans;

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top() != -1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans.push_back(st.top());
            }

            st.push(i);
        }
        return ans;
    }

    vector<int> right(vector<int>& nums) {
        vector<int> ans;

        stack<int> st;
        st.push(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() != nums.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans.push_back(st.top());
            }

            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& nums) {
        vector<int> l = left(nums);
        vector<int> r = right(nums);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
           int a = r[i] - l[i] -1;
           int b = nums[i];
           ans = max(a*b , ans);
        }
        return ans;
    }
};
