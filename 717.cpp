/**
 * #717 1-bit and 2-bit Characters
 *
 * We have two special characters.
 * The first character can be represented by one bit 0.
 * The second character can be represented by two bits (10 or 11).
 *
 * Now given a string represented by several bits.
 * Return whether the last character must be a one-bit character or not.
 * The given string will always end with a zero.
 *
 * 1 <= len(bits) <= 1000.
 * bits[i] is always 0 or 1.
 *
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() > 1 && bits[bits.size() - 2] == 0) {
        	return true;
        }

        // count the numbers of consectuive ones before the last 0
        // even no. -> last bit must be single char
        int ones = 0;
        for (int i = bits.size() - 2; i >= 0; i--) {
        	if (bits[i] == 1) {
        		ones++;
        	} else {
        		break;
        	}
        }

        return ones % 2 == 0;
    }
};
