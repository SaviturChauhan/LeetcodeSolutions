class Solution {
public:
    int rearrangeCharacters(string s, string target) {
       vector<int> freq1(26,0);
       vector<int> freq2(26,0);
       for(auto & ch : s){
        freq2[ch-'a']++;
       }
       for(auto & ch : target){
        freq1[ch-'a']++;
       }
       int mini = INT_MAX;
       for(int i = 0;i<26;i++){
        if(freq1[i] != 0){
            mini = min(freq2[i]/freq1[i],mini);
        }
       }
       return mini;
        
    }
};