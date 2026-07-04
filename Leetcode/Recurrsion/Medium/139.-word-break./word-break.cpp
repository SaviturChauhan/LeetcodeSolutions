bool wordBreak(string s, vector<string>& wordDict) {
     }
        }
            if(st.find(temp) != st.end() && solve(idx+l,s,dp)) return dp[idx] = true;
        return dp[idx] = false;
            string temp = s.substr(idx,l);
        for(int l = 1;l<n;l++){
        if(dp[idx] != -1) return dp[idx];
        if(st.find(s) != st.end()) return true;
        }
            return true;
        if(idx >= n){
    bool solve(int idx,string s,vector<int> &dp){

    unordered_set<string> st;
    int n;
public:
class Solution {
        n = s.size();
        for(auto & it: wordDict){
            st.insert(it);
        }
        vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }
};