/**
 * #1470 Shuffle the Array
 *
 * Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
 *
 *  1 <= n <= 500
 *  nums.length == 2n
 *  1 <= nums[i] <= 10^3
 *
 */

class Solution {
public:
	// O(n) time, O(n) space
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> newNums;
        for (int i = 0; i < n; i++) {
        	newNums.push_back(nums[i]);
        	newNums.push_back(nums[i + n]);
        }
        return newNums;
    }

    // O(n) time, O(1) space
    vector<int> betterShuffle(vector<int>& nums, int n) {
    	// swap elements into desired index in-place
    	// then mark negative to indicate it was swapped
        for (int i = 0; i < nums.size(); i++) {
        	if (nums[i] < 0) continue;

        	int cur = i;
        	int next = (cur < n) ? 2 * cur : 2 * (cur - n) + 1;
        	int val = nums[i];
        	while (nums[next] > 0) {
	        	int temp = val;
	        	val = nums[next];
	        	nums[next] = -temp;
	        	cur = next;
	        	next = (cur < n) ? 2 * cur : 2 * (cur - n) + 1;
        	}
        }

        // revert the negation
        for (int i = 0; i < nums.size(); i++) {
        	nums[i] = -nums[i];
        }

        return nums;
    }
};
