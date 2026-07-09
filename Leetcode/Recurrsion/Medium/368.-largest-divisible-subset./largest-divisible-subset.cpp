}
        vector<int> temp;
        temp.push_back(arr[lastidx]);
        while (hash[lastidx] != lastidx) {
            lastidx = hash[lastidx];
            temp.push_back(arr[lastidx]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return longestLIS(nums);
    }
};