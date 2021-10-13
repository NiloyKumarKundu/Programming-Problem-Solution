class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int numToFind = target - nums[i];
            
            if (mp.find(numToFind) != mp.end()) {
                v.push_back(mp[numToFind]);
                v.push_back(i);
                return v;
            }
            mp[nums[i]] = i;
        }
        
        return v;
    }
};