class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }  
};


// https://leetcode.com/explore/learn/card/binary-search/138/background/1038/discuss/423162/Binary-Search-101


// Time complixity: O(log2(n))