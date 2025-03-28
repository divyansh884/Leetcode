class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> lastIndex; 
        int maxLength = 0;
        int left = 0; 
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            if (lastIndex.find(ch) != lastIndex.end() && lastIndex[ch] >= left) {
                left = lastIndex[ch] + 1;
            }

            lastIndex[ch] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};