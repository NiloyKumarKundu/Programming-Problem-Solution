class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n), fromEnd(n);
        fromBegin[0] = 1, fromEnd[0] = 1;
        
        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
            fromEnd[i] = fromEnd[i - 1] * nums[n - i];
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(fromBegin[i] * fromEnd[n - 1 - i]);
        }
        
        return ans;
    }
};