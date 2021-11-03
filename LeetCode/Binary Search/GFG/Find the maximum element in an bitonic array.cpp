// Bitonic Array means the elemnet of the array in the 1st half is in accending order and the other half is in descending order.



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        if (nums.size() == 1) {
            return 0;
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if ((mid > 0) && (mid < nums.size() - 1)) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid - 1] > nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return 0;
                } else {
                    return 1;
                }
            } else if (mid == nums.size() - 1) {
                if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
                    return nums.size() - 1;
                } else {
                    return nums.size() - 2;
                }
            }
        }
        return 0;
    }
};









// Another way...


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = mid1 + 1;
            
            if (nums[mid1] < nums[mid2]) {
                low = mid2;
            } else {
                high = mid1;
            }
        }
        return low;
    }
};