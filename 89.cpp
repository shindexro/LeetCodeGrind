/**
 * #89 Gray Code
 *
 * The gray code is a binary numeral system where
 * two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing 
 * the total number of bits in the code,
 * print the sequence of gray code. 
 * A gray code sequence must begin with 0.
 *
 */

class Solution {
public:
	// O(2^n) time, O(2^n) space
    vector<int> grayCode(int n) {
        vector<int> gray { 0 };

        // incrementally build up the gray code
        // grayCode(n) = grayCode(n-1) + (grayCode(n-1) reversed and +2^n)
        for (int i = 0; i < n; i++) {
        	int head = 1 << i;
        	for (int j = gray.size() - 1; j >= 0; j--) {
        		gray.push_back(head + gray[j]);
        	}
        }

        return gray;
    }
};
