class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int cur = 0;
        vector<int> sums;
        for (int n : nums) {
            cur += n;
            sums.push_back(cur);
        }
        return sums;
    }
};