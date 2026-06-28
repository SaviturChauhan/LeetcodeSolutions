class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int maxel = INT_MIN;

        arr[0] = 1;
        for(int i = 1;i<n;i++){
           arr[i] = min(arr[i],arr[i-1]+1);
        } 

    return arr[n-1];
    }
};