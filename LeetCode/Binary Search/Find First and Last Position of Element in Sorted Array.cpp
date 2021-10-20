class Solution {
public:
    
    int findStartPosition(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int start = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                start = mid;
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return start;
    }
    
    int findEndPosition(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int end = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                end = mid;
                l = mid + 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return end;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        res[0] = findStartPosition(nums, target);
        res[1] = findEndPosition(nums, target);
        return res;
    }
};