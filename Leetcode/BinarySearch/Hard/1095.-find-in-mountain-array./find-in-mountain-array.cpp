/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int BinarySearch(MountainArray &mountainArr,int target,int l , int r){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
    int BinarySearchr(MountainArray &mountainArr,int target,int l , int r){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pivot = -1;
        int l = 1;
        int r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid-1)){
               pivot = mid;
               l = mid+1;
            }else{
                r = mid-1;
            }
        }
        //first half
        int idx = BinarySearch(mountainArr,target,0,pivot);
        if(idx != -1) return idx;
        return BinarySearchr(mountainArr,target,pivot+1,n-1);
    }
};