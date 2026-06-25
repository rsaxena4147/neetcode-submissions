#include<bits/stdc++.h>
class Solution {
public:
    int dp[1001][1001];
    bool isPal(int i , int j  , string& s){
        if(i >= j)return true;
        if(s[i] != s[j])return dp[i][j] = false;

        return dp[i][j] = isPal(i + 1 , j - 1 , s);

    }
    string solve(string &s){
        int len = 0;
        int start = -1;
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){

                if(isPal(i , j , s) && len < (j - i + 1)){
                    start = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
    string longestPalindrome(string s) {
        memset(dp , -1 , sizeof(dp));
          return solve(s);
    }
};
