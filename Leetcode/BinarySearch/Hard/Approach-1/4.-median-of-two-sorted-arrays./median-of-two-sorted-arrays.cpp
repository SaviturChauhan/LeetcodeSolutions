class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;
        int k = 0;
         int size = m+n;
        //vector<int> temp(m + n);
        int idx1 = (size/2) -1;
        int ele1 = 0,ele2 = 0;
        int idx2 = (size/2);


        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                if(k == idx1) ele1 = nums1[i];
                if(k == idx2) ele2 = nums1[i];
                i++;
                k++;
            } else {
                if(k == idx1) ele1 = nums2[j];
                if(k == idx2) ele2 = nums2[j];
                j++;
                k++;
            }
        }

        while (i < n) {
            if(k == idx1) ele1 = nums1[i];
            if(k == idx2) ele2 = nums1[i];
            i++;
            k++;
        }
        while (j < m) { 
            if(k == idx1) ele1 = nums2[j];
            if(k == idx2) ele2 = nums2[j];
            j++;
            k++;
        }

       

        if((size % 2 )!= 0) return ele2;
        return (ele1 + ele2)/2.0;
    }
};