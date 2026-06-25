class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> vis(strs.size() , 0);
        for(int i = 0 ; i < strs.size() ; i++){
            if(vis[i])continue;
            string s = strs[i];
            sort(s.begin() , s.end());
            vector<string> store;
            store.push_back(strs[i]);
            for(int j = i+1 ; j < strs.size() ; j++){
                if(vis[j])continue;
               
                string st = strs[j];
                sort(st.begin() ,st.end());

                if(st ==s){
                    store.push_back(strs[j]);
                     vis[j]=1;
                }
            }
            ans.push_back(store);
        }
        return ans;
    }
};
