class Solution {
public:
    
    vector<int> dig = {1,2,3,4,5,6,7,8,9};
    set<vector<int>> st;

    void f(int k, int n,int idx,vector<int> & curr){
        if(n == 0 && k == 0){
            st.insert(curr);
            return;
        }
        if(n<0 || idx > 8) return;

        //take
        curr.push_back(dig[idx]);
        f(k-1,n-dig[idx],idx+1,curr);
        curr.pop_back();

        //Not take
        f(k,n,idx+1,curr);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        int idx = 0;
        f(k,n,idx,curr);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};