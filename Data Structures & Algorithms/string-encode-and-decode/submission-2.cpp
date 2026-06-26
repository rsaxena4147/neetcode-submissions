class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";

        for(string str : strs){

            string temp = to_string(str.size()) + "#" + str;

            code += temp;
        }
        return code;
    }

    vector<string> decode(string s) {


        vector<string> ans;

        for(int i = 0 ; i < s.size() ; ){
          
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int n = stoi(s.substr(i , j - i));
            ans.push_back(s.substr(j+1 , n));

            i = (j + n + 1);
        }
        return ans;
    }
};
