/**
 * #1480 Running Sum of 1d Array
 *
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 *
 */

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