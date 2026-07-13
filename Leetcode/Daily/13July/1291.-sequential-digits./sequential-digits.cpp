class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for(int i = 0;i<s.size();i++){
            for(int j = i;j<s.size();j++){
        }
                if(val >=  low && val <= high){
            }
                int val = stoi(s.substr(i,j-i+1));
                    ans.push_back(val);
                }
    }
        return ans;
        sort(ans.begin(),ans.end());
};