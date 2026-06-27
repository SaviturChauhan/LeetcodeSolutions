class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    void solve(string s,string curr,int i){
        if(i >= s.size()){
            ans.push_back(curr);
            return;
        }

        for(int j = i;j<s.size();j++){
            string word  = s.substr(i,j-i+1);
            if(st.count(word)){
                string temp = curr;
                if(!curr.empty()){
                    curr += " ";
                }
                curr += word;
                solve(s,curr,j+1);
                curr = temp; //undo
            }
            
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string curr = "";
        for(auto & it: wordDict){
            st.insert(it);
        }
        solve(s,curr,0);
        return ans;
    }
};