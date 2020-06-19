/**
 * Problem 0003 Longest Substring Without Repeating Characters
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window method
        int left = 0;
        int right = 0;
        unordered_map<char, int> inWindow;  // maps char to its index
        int longest = 0;

        while (right < s.size()) {
            if (inWindow.find(s[right]) == inWindow.end()
                    || inWindow[s[right]] < left) {
                inWindow[s[right]] = right;
                right++;
                longest = (right - left > longest) ? right - left : longest;
            } else {
                left = inWindow[s[right]] + 1;
            }
        }
        return longest;
    }
};
