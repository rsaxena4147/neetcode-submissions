class Solution {
   public:
    int characterReplacement(string s, int k) {
        int st = 0;
        int en = 0;
        int n = s.size();
        int maxi_freq = INT_MIN;
        unordered_map<char, int> mp;
        int ans = 0;

        while (en < n) {
            mp[s[en]]++;

            maxi_freq = max(maxi_freq, mp[s[en]]);

            if ((en - st + 1) - maxi_freq > k) {
                mp[s[st]]--;
                st++;
            }
            
            ans = max(ans, en - st + 1);
            en++;

        }
        return ans;
    }
};
