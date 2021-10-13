class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        
        for (auto q : queries) {
            int count = 0; 
            int r = q[2] * q[2];
            
            for (auto p : points) {
                // x^2 + y^2 <= r^2
                count+= (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= r;
            }
            ans.push_back(count);
        }
        return ans;
    }
};