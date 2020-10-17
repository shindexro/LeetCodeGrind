/**
 * #1431 Kids With the Greatest Number of Candies
 *
 * Given the array candies and the integer extraCandies, 
 * where candies[i] represents the number of candies that the ith kid has.
 *
 * For each kid check if there is a way to distribute extraCandies among the kids
 * such that he or she can have the greatest number of candies among them.
 * Notice that multiple kids can have the greatest number of candies.
 *
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int needCandies = maxElement(candies) - extraCandies;
        vector<bool> canHaveMaxCandy;

        for (int c : candies) {
        	if (c >= needCandies) {
        		canHaveMaxCandy.push_back(true);
        	} else {
        		canHaveMaxCandy.push_back(false);
        	}
        }

        return canHaveMaxCandy;
    }

    int maxElement(vector<int>& arr) {
    	if (!arr.size()) {
    		throw invalid_argument("Empty list.");
    	}

    	int curMax = arr[0];
    	for (int i = 1; i < arr.size(); ++i) {
    		if (arr[i] > curMax) {
    			curMax = arr[i];
    		}
    	}
    	return curMax;
    }
};