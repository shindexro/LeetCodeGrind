/**
 * #1512 Number of Good Pairs
 *
 * Given an array of integers nums.
 *
 * A pair (i,j) is called good if nums[i] == nums[j] and i < j.
 *
 * Return the number of good pairs.
 *
 */

class Solution {
public:
	// O(n) time, O(n) space
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) {
        	if (count.find(n) != count.end()) {
        		count[n] += 1;
        	} else {
        		count[n] = 1;
        	}
        }

        int pairs = 0;
        for (auto const& c : count) {
        	pairs += c.second * (c.second - 1) / 2;
        }
        return pairs;
    }
};