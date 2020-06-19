/*
 *  #0001 Two Sum
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nmap;
        
	    for (int i = 0; i < nums.size(); i++) {
	        int desire = target - nums[i];
	        if (nmap.find(desire) != nmap.end()) {
	            return {nmap[desire], i};
            }
            nmap[nums[i]] = i;
	    }
	    return {-1, -1};  // no solution found, should not reach
    }
};

